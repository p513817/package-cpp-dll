#include <iostream>
#include <string>
#include <string_view>
#include "foo_export.h"

class FOO_EXPORT Foo
{
public:
    Foo(std::string_view name);
    ~Foo();

    const std::string_view GetName() const;
    void Print() const;

private:
    std::string m_name{};
};