function matrix = question9(M, CMD)
elements = numel(M); % Count the elements in the Matrix
if CMD == 1
    for i=1:elements % Goes over the whole matrix to check the sign of every element
        if M(i) > 0
            M(i) = 1;
        else
            M(i) = 0;
    end
end
M % Present the matrix
elseif CMD == 2
    M(:,1:2:end) = elements % Insert the N elements to the odd colums 
elseif CMD == 3
    M(M >= 3 & M <= 5) = 0 % Set 0 for all the elements between 3-5
elseif CMD == 4
    M(1,:) = max(M(1,:),0) % This function change all the negative numbers (smaller                       than 0) to 0. It contains to the first row of M.
end
    
    
    
    
    
