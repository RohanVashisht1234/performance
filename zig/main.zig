const std = @import("std");
const stdout = std.io.getStdOut().writer();
const LIMIT = 100;

fn generateFibonacci(fib: []u128, n: usize) void {
    fib[0] = 0;
    fib[1] = 1;
    for (0..n - 2) |i| {
        fib[i + 2] = fib[i + 1] + fib[i];
    }
}

fn function_to_benchmark() void {
    var fib: [LIMIT]u128 = undefined;
    generateFibonacci(&fib, LIMIT);
}

pub fn main() !void {
    var t = std.time.Timer.start() catch unreachable;
    function_to_benchmark();
    const elapsed = t.read();

    std.debug.print("Zig: {} nanoseconds.\n", .{elapsed});
}
