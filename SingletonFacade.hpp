#pragma once
class SingletonFacade {
    SingletonFacade() = default;
public:
    static SingletonFacade& get_instance() {
        static SingletonFacade instance;
        return instance;
    }
    SingletonFacade(SingletonFacade const&) = delete;
    void operator=(SingletonFacade const&) = delete;
};