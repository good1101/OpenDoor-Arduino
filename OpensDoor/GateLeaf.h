class GateLeaf
{
  public:
    GateLeaf(byte pinRele1, byte pinRele2, byte pinVoltage)
    {
      _pinRele1 = pinRele1;
      _pinRele2 = pinRele2;
      _pinVoltage = pinVoltage;
      pinMode(_pinRele1, OUTPUT);
      pinMode(_pinRele2, OUTPUT);
      pinMode(_pinVoltage, OUTPUT);
    }
    void close()
    {
      voltageOff();
      delay(200);
      digitalWrite(_pinRele2, 1);
      Serial.println("rele1 0");
      digitalWrite(_pinRele1, 0);
      delay(200);
      voltageOn();
    }

    void open()
    {
      voltageOff();
      delay(200);
      digitalWrite(_pinRele2, 0);
      Serial.println("rele1 1");
      digitalWrite(_pinRele1, 1);
      delay(200);
      voltageOn();
    }

    void stop()
    {
      Serial.println("stop");
      voltageOff();
      delay(200);
      digitalWrite(_pinRele1, 0);
      digitalWrite(_pinRele2, 0);
    }
  private:
    byte _pinRele1;
    byte _pinRele2;
    byte _pinVoltage;

    void voltageOn()
    {
      Serial.println("v on 1");
      digitalWrite(_pinVoltage, 1);
    }

    void voltageOff()
    {
      Serial.println("v off 0");
      digitalWrite(_pinVoltage, 0);
    }

};
