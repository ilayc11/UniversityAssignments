count = 0;
for i=1:100
    if isprime(i) % The function checks if the number is prime
            count = count + 1;
    end
end
disp([num2str(count), " prime numbers exist between 1-100"])



            
