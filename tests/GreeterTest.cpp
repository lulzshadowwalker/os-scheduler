#include "../vendor/cest/cest"
#include "Greeter.hpp"
#include <string>

describe("Greeter", []() {
    it("greeter people with their name", []() {
        Greeter greeter;
        expect(greeter.greet("lulz")).toBe("Hello, lulz!");
    });
});
