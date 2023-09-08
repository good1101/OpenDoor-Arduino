using CallbackOnPress = void (*)(void);

class Button
{
  public:
    Button(byte pin, bool isReversButton)
    {
      _pin = pin;
      _isReversButton = isReversButton;
      if (_isReversButton)
        pinMode(_pin, INPUT_PULLUP);
      else
        pinMode(_pin, INPUT);
    }

    void setCallbackPress(CallbackOnPress onPress)
    {
      _onPress = onPress;
    }

    void check()
    {
      bool _btState = digitalRead(_pin);
      if (_isReversButton)
      {
        _btState = !_btState;
      }

      if (_btState != _btLastState)
      {
          delay(_pausePress);

      }
      if (_btState && !_btLastState)
      {
        if (_isReversButton)
          Serial.print("revers; ");
        Serial.print("Сигнал на пин ");
        Serial.println(_pin);
        _startPress = millis() / 1000;
      }
      if(!_btState)
        _startPress = millis() /1000;
      if(_startPress + _pressTimeSecond  < millis() / 1000)
        _onPress();

      _btLastState = _btState;
    }

  private:
    byte _pin;
    CallbackOnPress _onPress;
    int _pausePress = 100;
    boolean _btLastState;
    boolean _isOpen;
    bool _isReversButton;
    long _startPress;
    int _pressTimeSecond = 1;
};
