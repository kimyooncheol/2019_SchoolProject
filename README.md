# 종합선물 시계

## 제작동기
![why.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/why.png?raw=true)
심박 수 센서와 리얼타임클록 모듈과 접목시켜 시계를 만들고<br>서버와 연동하여 측정한 데이터를 저장하고, 차트화 시키면 어떨까 하여 제작하게 되었다.
## 제작 과정
![made2.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/map.PNG?raw=true)
구조도 제작
![made1.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/made_1.PNG?raw=true)
하우징 3D 설계
![made2.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/made_2.PNG?raw=true)
시제품 제작
![made3.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/made_3.PNG?raw=true)
소자 모듈화
![made4.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/made_4.PNG?raw=true)
조립
## 완성
![body.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/map.PNG?raw=true)
조립이 끝난 몸체
![web.png](https://github.com/kimyooncheol/2019_SchoolProject/blob/master/image/web.PNG?raw=true)
차트와 그래프가 포함된 페이지
## 성과
- 전공동아리 발표 우수상
- 백엔드와 프론트엔드 기초 공부
## 버그
- 아두이노측에서 WIFI로 통신하는 부분의 작동이 확인되지 않았다.  
## 개발자
- 하우징 설계 및 제작: 김영원
- 코딩 및 회로 설계: 김윤철
```
# 사용된 기술
- PHP: Database와 연동 및 구글 차트로 json 데이터 보내기
- MySQL: 심박수 저장 Database
- Arduino: -시계모드: 리얼타임 클록을 사용한 현제 시각및 온습도 센서 데이터 LCD출력
           -측정모드: 심박수 및 적외선 체온계로 인체 데이터 수집 후 서버로 전송
- GoogleChart: 측정된 심박수 그래프화
```
