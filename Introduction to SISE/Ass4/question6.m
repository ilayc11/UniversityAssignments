v = [3 4]
for i = 3:1000
    v(i) = v(i-1) + 2 * v(i-2) + 5; % create the values by the rule
end
v = log10(v); % values in v is growing fast that we can't see the graph
x = 1:1:1000;
figure(1)
plot(x,v)