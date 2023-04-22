function sum = formulaA(n,x)
sum = 0;
for i=1:n % calculate the sum by a loop 
    sum = sum + i/x;
end

function sqrt_calculate = formulaB(a,b,c)
sqrt_negative = (-b - sqrt(b ** 2 - 4 * a * c))/(2 * a);
sqrt_positive = (-b + sqrt(b ** 2 - 4 * a * c))/(2 * a);
sqrt_calculate = (sqrt_negative, sqrt_positive);
end
% calculate the 2 sqrts (+ and -)

function y = formulaC(x)
if x == 0
    disp("ERROR - Division by 0")
else  
    y = e ** x - 1/(x ** 5);
end
