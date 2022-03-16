#include <iostream>

template<typename T>
class Singleton {

public:
    Singleton(Singleton &other) = delete;
    Singleton &operator=(const Singleton &) = delete;

protected:
    Singleton() = default;
    ~Singleton() = default;


public:
    static T *GetInstance() {
        static  T *_instance;
        if (_instance == nullptr)
        {
            _instance = new T();
        }

        return _instance;
    }

};

// Пример класса, используещего Singleton
class GameState : public Singleton<GameState> {

public:
    void SetValue(int value) { _value = value; }
    int GetValue() const { return _value; }

private:
    int _value = -1;
};

void test1() {
    GameState *state = GameState::GetInstance();
    std::cout << state->GetValue() << std::endl;
    state->SetValue(99);
}

void test2() {
    GameState *state = GameState::GetInstance();
    std::cout << state->GetValue() << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}
