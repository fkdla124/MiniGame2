# 📌 [객체지향 콘솔 슈팅 게임 미니프로젝트]

객체지향으로 구현하는 콘솔 슈팅 게임 미니프로젝트입니다. <br>
![game](game.gif)

<br>

# 🎯 제작 목적

- 전반적인 게임루프의 흐름을 객체지향 코드로 표현하는 연습을 위함.
- 객체지향이 무엇인지 직접 몸으로 느껴보기 위해. 최대한 각 객체들이 본인의 로직을 직접 수행하는 구조로 작업.
- 게임엔진, 프레임워크의 구조를 일부 학습하기 위함. 가상함수의 다형성을 활용하여 오브젝트나 씬을 추가할 때 BaseClass를 상속하여 Update(), Render()등을 오버라이딩하기만 하면 알아서 동작.

<br>

# 🛠️ 사용 기술

- C++
- 객체지향
- 가상함수의 다형성을 활용한 프레임워크적 사고
- 직접 만든 Iterator + List

<br>

# ⚙️ 주요 기능

- 타이틀씬, 게임씬, 게임클리어씬, 게임오버씬 총 4개의 씬으로 구성.
- 플레이어는 움직이며 총을 발사하는 적군을 모두 죽여야 게임 클리어.
- 게임씬을 제외한 다른 씬에서 q를 눌러 게임의 정상적인 종료.

<br>

# 🏗️ 구조

### 게임 진행 흐름. 
TitleScene -> GameScene -> Game Clear/Over Scene -> ExitScene

### Manager
- ConsoleManager
- FPSManager
- ObjectManager
- SceneManager
- ScreenManager
- TimeManager

### Object
- ObjectType
- BaseObject
- Player
- PlayerBullet
- Enemy
- EnemyBullet

### Scene
- BaseScene
- TitleScene
- GameScene
- Game Clear/Over Scene
- ExitScene

### Main
- SceneManager::Run()

<br>

# 🔥 문제 해결

### [타이틀에서 게임 시작 시 모든 오브젝트가 소멸되는 문제]

LoadScene(new nextScene); 을 호출하여 다음 씬을 미리 생성해두고. 이번 프레임의 할 일을 모두 마치고 마지막에 현재 씬을 파괴하며 받아둔 다음씬으로 교체함. <br>
<br>
각 씬의 생성자에서 오브젝트 생성. <br>
각 씬의 소멸자에서 오브젝트 파괴. <br>
<br>
즉. 씬의 교체 방식이 지연 교체이다보니 이전씬의 소멸, 다음씬의 생성 순서가 서로 뒤바뀌면서 다음씬을 위해 만들어진 오브젝트들이 이전씬의 소멸과함께 전부 사라짐. <br>

### 해결방안

BaseScene에 OnInit(), OnDestroy() 가상함수를 만들어 씬마다 오버라이딩. <br>
각자의 씬에 맞게 초기화, 소멸 작업을 따로 함수로 마련. <br>
이후 만들어진 함수를 이용하여 씬마다의 초기화, 소멸 작업을 원하는 시점에 호출하도록 구조를 변경하여 작업의 순서를 정상적으로 보존하며 해결. <br>

### 배운 점

생성자, 소멸자를 활용하여 씬마다 초기화, 소멸 작업을 지정하는 것보다 <br>
OnInit(), OnDestroy() 멤버함수를 따로 만들어 관리하는 방법이  <br>
작업의 순서를 내가 원하는 시점으로 관리하기 용이하다는 점을 배움. <br>
