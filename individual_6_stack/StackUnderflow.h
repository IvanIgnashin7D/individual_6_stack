#pragma once
#include <iostream>

class StackUnderflow : public std::exception {
public:
    StackUnderflow(const std::string& message = "Stack underflow: cannot pop element, stack is empty.")
        : message_(message) {}

    virtual const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};