# OSEK/VDX OS
## Task
- OS가 제어하는 프로그램의 기본 단위
- 복잡한 제어 소프트웨어의 실시간 요구사항을 나누어 여러 task로 구성
- ex) 주기 task, 인터럽트 발생 시에만 동작하는 task
## **Task State Model**
- Task는 실행되면서 상태가 변함
- OSEK에서는 2타입의 Task 상태에 대한 model을 제공 ► Basic Task, Extended Task
- 각 Task 별로 Basic Task 와 Extended Task 중 선택하여 사용

#### Basic task
    <states>
    - running: CPU가 task에 할당되어 instruction 수행, 한 번에 하나의 task만이 running 상태에 있을 수 있음
    - ready: running에 들어가기 위해 우선 거쳐야 하는 state, scheduler는 ready state에 있는 task 중 다음에 실행할 task를 결정
    - suspended: 휴식 상태, activated 될 수 있음

    <State Transition>
    - start: ready state에서 scheduler가 task를 선택하였을 때 실제 동작 상태로 들어가는 전이
    - preempt: scheduler가 다른 task를 시작하기로 결정하여 running에서 ready로 돌아가는 전이
    - activate: system service에 의해 task가 실행 준비되었을 때 발생
    - terminate: task가 종료되거나 에러로 인해 task가 강제로 종료될 때 발생
#### Extended task
    <states>
    - Basic tasks의 state 를 포함 (running, suspended, ready)
    - wait : 특정 event가 발생하기 전까지 동작하지 않는 상태가 추가됨

    <State Transition>
    - Basic task의 State Transition을 포함 (start , preempt ,terminate, activate)
    - wait : system service에 의해 발생. 동작을 이어가려면 event 가 발생하여야 함 (Context 저장이 필요)
    - release : waiting state에 있는 task에 event 가 발생하였을 때 Ready 로 옮겨가게 됨

## Scheduling
### Multi-Tasking (OS)
- 시스템은 여러 개의 Task를 실시간 상에서 동시에 실행 (Concurrency)
- Single core 환경에서는 실제 복수의 Task를 '동시에' 실행할 수 없음
- Multi-Tasking을 위해서는 준비 큐에 있는 어느 Task에게 CPU를 할당할 것인지 스케줄링을 수행해야 함

### Priority 기반의 Scheduling
- ready/running state 상의 모든 task 검색
- Highest priority를 가진 Task 집합 결정
- 그 중에서 가장 먼저 들어온 Task 찾기
- 찾아낸 Task를 running 상태로 전환


### Scheduling되어 Task가 running 상태에 있을 때 더 높은 Priority를 가지는 Task가 activate 된다면?

- **Scheduling 방식**에 따라 다른 동작을 취함 (Full Preemptive, Non Preemptive)

- #### [Full Preemptive 방식]
    - Task가 activate 되었을 경우 다시 Scheduling하여 더 높은 우선순위를 가진 Task가 먼저 수행됨.
    - 설명 : Task T2가 실행되는 도중에 높은 우선순위를 가지는 T1이 선택하여 Task를 먼저 수행.

- #### [Non Preemptive 방식]
    - task가 activation 되더라도 scheduling이 일어나지 않고 현재의 task를 끝까지 수행.
    - 설명 : 우선순위가 높아도 Task T2가 종료될 때까지 ready 상태에 머무름.

## Context Switching

- **Task 선점 시 동작**
  - **Context switching**이 발생
    - **Context switching**: 선점되는 TASK의 Context를 저장하고, 새로 실행되는 TASK의 Context를 불러오는 것

- **Context**
  - MCU가 현재 실행 중인 TASK의 상태 (program counter, register 값 등 task 수행을 위해 가지고 있어야 하는 값들)

- **Context Save**
  - 현재 실행 중인 TASK의 상태 정보(Registers - IP, SP, ...)를 MCU로부터 가져와 메모리에 저장하는 것

- **Context Load**
  - 새로 실행할 TASK의 상태 정보를 메모리로부터 가져와서 현재 MCU에 반영하는 것
    - 예시 : 메모장과 엑셀 간의 context switching

- **Basic task에서의 Context Switching**
  - Task가 선점될 때 Context를 저장하고 다시 running 상태로 전이될 때 저장했던 Context를 불러옴

- **Extended task에서의 Context Switching**
  - Task가 선점될 때 Context를 저장하고 다시 running 상태로 전이될 때 저장했던 Context를 불러옴
  - Task가 wait 상태로 전이할 때 Context를 저장하고 다시 running 상태로 전이될 때 저장했던 Context를 불러옴

### PreTaskHook / PostTaskHook

- **TaskHook이란?**
  - 디버깅이나 타이밍 정보 측정 등을 위하여 Task 동작 전후로 사용자가 작성하여 사용할 수 있는 루틴

- **동작 방식**
  - 동작 순서: `PreTaskHook` ➔ Task running ➔ `PostTaskHook`
  - running state에 들어간 직후 `PreTaskHook` 동작
  - running state에서 나오기 직전에 `PostTaskHook` 동작
  - `TaskHook` 동작 시 task의 상태는 Running 상태를 유지
  - `TaskHook` 내에 사용자의 루틴을 작성
    - 예시: `PreTaskHook`과 `PostTaskHook`에서 각각 `timestamp`를 사용하여 Task의 수행 시간을 측정

## Event
### 사용 용도
- **Waiting state**를 지원하는 task에 대하여 task 간 동작 순서를 동기화할 수 있는 **mechanism** 제공
- Task의 동작 순서를 동기화하기 위해 사용
  - 예시: Task B의 연산 결과가 필요한 경우 연산 결과가 준비되었다는 event 발생 시까지 wait

### Event mechanism
- **Running state**의 extended task는 지정된 이벤트가 발생할 때까지 **wait state**에서 대기
- **Waiting state**의 extended task는 대기하고 있던 최소 한 개의 이벤트가 발생되면 **ready state**로 전이
- 이벤트가 이미 발생된 상태에서 동작 중인 extended task가 해당 이벤트를 wait 하는 경우, 그 Task는 running 상태 유지

### 사용시 제약
- Event를 사용할 수 있는 것은 **Extended Task**에서만 가능
  ➔ Task가 Waiting 상태를 지원해야 하기 때문
- Event를 set하는 것은 **Basic Task**에서도 가능

## Interrupt
    - 주변 장치에서 발생한 상태 변화
    - 예시 : CAN signal receive, Timer expired

### Interrupt 특징
- Interrupt는 Task들을 선정함
  - (Full Preemptive, Non Preemptive 상관 없이) ➔ Context switching 발생
- Interrupt는 Category1과 Category2로 분류 가능
- 우선순위: Interrupt level > Logical level for scheduler > Task level

### Interrupt 분류

- **Category1 Interrupt**
  - OS 서비스를 사용하지 않는 ISR(Interrupt Service Routine)
  - ISR이 끝난 후 직전에 처리 중이던 구문을 계속 처리
  - 인터럽트가 task 관리에 영향을 주지 않음
  - ISR이 최소한의 오버헤드를 가짐

- **Category2 Interrupt**
  - OS 서비스를 사용하는 ISR
  - OS가 지정된 사용자 routine을 위해 런타임 환경을 제공하는 ISR-frame을 제공함
  - system generation 중에 사용자 루틴이 interrupt에 할당


### Interrupt와 Task 간 스케줄링

- ISR 중에는 rescheduling이 발생하지 않음
- ISR cat.2가 종료되었을 때 다른 interrupt가 없다면 task에 대하여 rescheduling 수행
- Interrupt에서 active된 task는 동작하는 모든 interrupt routine이 끝나야 schedule
- Nested interrupts of different category 문제
  - Cat.1 ISR 도중에 Cat.2 ISR 발생하여 task를 activate 시키는 경우 cat.1 ISR이 끝났을 때 OS를 call 하지 않아 activate시킨 task에 대하여 unbounded delay가 발생
  - Ex. solution) 모든 Cat.1 ISR의 priority가 Cat.2 ISR보다 같거나 높으면 됨

## Alarm
    - Counter에 기반하여, 특정 시점에 도달하였을 경우 지정된 동작 (task activation, set event 혹은 alarm-callback) 함으로써 반복적인 이벤트를 발생시킬 수 있도록 하는 OS의 객체

### 주요 용도
- OS 내 구성된 Task를 **주기적**으로 실행 시키기 위해 사용

### Counter
- Counter는 소스(e.g. Timer)의 값을 TICK 단위의 상수 값으로 변경시킴 (e.g. 1ms → 1tick)
- OSEK OS는 S/W 혹은 H/W Timer와 연결된, 적어도 하나의 COUNTER를 제공
### Alarm의 동작
- ALARM은 COUNTER가 미리 정의된 값에 도달했을 경우 expire되고, 이 때 하기 동작이 가능
  - Call Alarm Callback (with CAT2 Interrupt disabled)
  - Activate Task
  - Set Event
  - Increment Counter (AUTOSAR Spec)

## Resource
    - 우선순위가 다른 여러 task가 공유된 자원에 병행 접근 하는 것을 조정 (임계 영역 보호)
        - 예) 스케줄러, 프로그램 순서, 메모리나 H/W 구역
    - Multi-Core 간에는 사용할 수 없음!!!

### Resource 종류
- **Standard**
  - `GetResource(ResID)` - Resource를 획득하는 API
  - `ReleaseResource(ResID)` - Resource를 반환하는 API

- **Internal**
  - `GetResource(ResID)`와 `ReleaseResource(ResID)` 사용 불가
  - Task가 running 상태에 진입할 때 자동으로 획득
  - Non-preemptive scheduling의 rescheduling의 지점에서 자동으로 release
  - 동작은 standard 리소스와 같음 (priority ceiling protocol 등)

- **Linked**
  - Resource에 대한 nesting 점유는 불가능함
  - 이를 원할 경우 원래의 resource와 동일한 동작을 하는 link resource를 추가함
### Priority Ceiling Protocol
- 우선순위 낮은 Task가 resource를 가지고 preemption될 때 발생할 수 있는 교착상태 해결을 위한 방법
- Resource를 얻는 순간에 resource에 지정된 priority로 task의 priority가 상승
- Resource를 release 하는 순간에 task는 원래의 priority로 돌아가고 Scheduling Policy가 preemptive일 경우 scheduling이 발생

#### Resource 제약 사항
- 동일 Resource에 대해 중첩해서 획득할 수 없음
- Task/ISR은 점유된 리소스를 가지고 종료할 수 없음
  - 예: TerminateTask, ChainTask, Schedule, WaitEvent의 호출 불가
- 한 개 task 안에서 다중 리소스 점유의 경우, 사용자는 LIFO(=stack) 방식으로 리소스를 request/release
- Resource를 사용하는 task의 우선순위는 Resource에 할당된 우선순위보다 크지 않아야 함

#### Scheduler as a Resource
- Task가 자신이 다른 Task들에 의해 선점되는 것으로부터 보호하려면, 스케줄러를 잠글 수 있음
  - `RES_SCHEDULER`이라는 이름 지어진 Standard Resource가 자동으로 생성
  - `RES_SCHEDULER`의 인터럽트를 제외한 tasks들의 re-scheduling을 방지
  - `RES_SCHEDULER`는 `GetResource(RES_SCHEDULER)`, `ReleaseResource(RES_SCHEDULER)`를 이용
- ※ AUTOSAR의 경우에는 `RES_SCHEDULER`가 자동으로 생성되지는 않음
