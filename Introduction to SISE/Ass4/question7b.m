function mirror = question7b(n)
if ~isnumeric(n)
    error('Error! must be a positive integer'); 
elseif floor(n) != n
    error('Error! must be a positive integer'); 
end
if n <= 0
    error('Error! must be a positive integer');
else
    v1 = 1:1:n;
    v2 = n:-1:1;
    disp([v1 v2]);
end

    
