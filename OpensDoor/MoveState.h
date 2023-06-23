

using CallbackMoveState = void (*)(void);

class MoveState 
{
  #include "Buttons.h"
  public:
    MoveState() {}
    
    void init(CallbackMoveState onMove, CallbackMoveState onStop, int moveTimeSecond )
    {
      _onMove = onMove;
      _onStop = onStop;
      _moveTimeSecond = moveTimeSecond;
    }
    
    void move()
    {
      _isMove = !_isMove;
      Serial.println("move");
      if (_isMove)
      {
        _onMove();
        _startMove = millis() / 1000;
      }
      else
      {
        _onStop();
      }
    }

    void check()
    {
      if(_isMove)
      {
        if( millis() / 1000 - _startMove  > _moveTimeSecond)
        {
          Serial.print("close");
          _isMove = false;
          _onStop(); 
        }
      }
    }

    void clear()
    {
      _isMove = false;
    }

  private:
    bool _isMove;
    CallbackMoveState _onMove;
    CallbackMoveState _onStop;
    long _startMove;
    int _moveTimeSecond;
};
