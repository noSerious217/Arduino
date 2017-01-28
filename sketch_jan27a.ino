class Engine
{
  private:
  int a1=0;
  int a2=0;
  int a3=0;
  int speed;
  boolean on[2];

  public:
  void initialize(int x, int y, int z)
  {
    a1=x;
    a2=y;
    a3=z;
    pinMode(a1,OUTPUT);
    pinMode(a2,OUTPUT);
    pinMode(a3,OUTPUT);
    analogWrite(a3,250);
    on[0]=false;
    on[1]=false;
    Serial.println(a2);
  }
  
  void forward()
  {
    on[0]=true;
    on[1]=false;
    digitalWrite(a1,HIGH);
    digitalWrite(a2,LOW);
  }
  
  void backward()
  {
    on[0]=false;
    on[1]=true;
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH); 
  }
  
  void reverse()
  {
    if (on[0])
    {
      on[0]=false;
      digitalWrite(a1,LOW);
    }
    else
    {
      on[0]=true;
      digitalWrite(a1,HIGH);
    }
    if (on[1])
    {
      on[1]=false;
      digitalWrite(a2,LOW);
    }
    else
    {
      on[1]=true;
      digitalWrite(a2,HIGH);
    }
  }  

  void stop()
  {
    on[0]=false;
    on[1]=false;
    digitalWrite(a1,LOW);
    digitalWrite(a2,LOW);
  } 
};

class Vehicle
{
  private:
  Engine FLE;
  Engine FRE;
  Engine BLE;
  Engine BRE;
  int stby1;
  int stby2;
  
  public:
  void init(int s1, int s2)
  {
    FLE.initialize(22,23,2);
    FRE.initialize(28,27,4);
    BLE.initialize(26,25,3);
    BRE.initialize(30,31,5);
    stby1 = s1;
    pinMode(stby1,OUTPUT);
    digitalWrite(stby1,HIGH);
    stby2 = s2;
    pinMode(stby2,OUTPUT);
    digitalWrite(stby2,HIGH);
  }
  
  void forward()
  {
    FLE.forward();
    FRE.forward();
    BLE.forward();
    BRE.forward();
  }

  void backward()
  {
    FLE.backward();
    FRE.backward();
    BLE.backward();
    BRE.backward();
  }

  void halt()
  {
    FLE.reverse();
    FRE.reverse();
    BLE.reverse();
    BRE.reverse();
    delay(5);
    FLE.stop();
    FRE.stop();
    BLE.stop();
    BRE.stop();
  }

  void clock()
  {
    FLE.forward();
    BLE.forward();
    FRE.backward();
    BRE.backward();
  }

  void againstclock()
  {
    FLE.backward();
    BLE.backward();
    FRE.forward();
    BRE.forward();
  }
  void stop()
  {
    FLE.stop();
    FRE.stop();
    BRE.stop();
    BLE.stop();
  }
};

class US
{
  private:
    long duration;
    int Trig_pin;
    int Echo_pin;
    long Timing()
    {
      digitalWrite(Trig_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(Trig_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(Trig_pin, LOW);
      duration = pulseIn(Echo_pin, HIGH);
      return duration; 
    }

    public:
    int init(int t,int e)
    {
      Trig_pin=t;
      Echo_pin=e;
      pinMode(t,OUTPUT);
      pinMode(e,INPUT);
    }
    long distance()
    {
      Timing();    
      return duration /29 / 2 ;
    }
};

Vehicle vh;
US detector;

void setup() {
  Serial.begin(9600);
  vh.init(24,29);
  detector.init(33,32);  
  vh.backward();
}

void loop() {
  if (detector.distance()<15) 
  {
    vh.halt();
    delay(10);
    vh.clock();
    delay(800);
    vh.stop();
    delay(10);
  }
  else
  {
    vh.backward();
    delay(10);
    vh.stop();  
    delay(1);
  }
 }

