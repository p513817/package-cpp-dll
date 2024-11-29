#include "foo.h"
#include <iostream>
#include <string>
#include <string_view>

Foo::Foo(std::string_view name)
    : m_name{ name } {
};

Foo::~Foo() {};

const std::string_view Foo::GetName() const
{
    return m_name;
}

void Foo::Print() const
{
    std::cout << "I'm " << m_name << "\n";
}