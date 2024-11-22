fn generate_fibonacci(limit: usize) -> Vec<u128> {
    let mut fib = vec![0u128; limit];
    fib[0] = 0;
    fib[1] = 1;
    for i in 2..limit {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    fib
}

fn main() {
    use std::time::Instant;
    let now = Instant::now();

    // Code block to measure.
    {
        const LIMIT: usize = 100;
        generate_fibonacci(LIMIT);
    }

    let elapsed = now.elapsed();
    println!("Rust: {} nanoseconds.", elapsed.as_nanos());
}
