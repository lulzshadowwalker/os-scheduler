#include <cest>
#include "Timer.hpp"

describe("Timer Device", []() {
    it("starts at 0", []() {
        Timer timer;
        expect(timer.time()).toBe(0);
    });

    it("returns the time in seconds since the timer device has started", []() {
        Timer timer;
        timer.tick();
        timer.tick();
        expect(timer.time()).toBe(2);
    });
});
