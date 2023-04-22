A = [zeros(3) zeros(3); zeros(3) reshape(1:9,3,3)']
% A: zeros creats matrix of 0. reshape creates matrix from line vector that runs from 1 to 9. the ' make it transpose. In the squre brrackets we combine all 4 matrix (3x3) to one big matrix (6x6).

M = toeplitz(1:3).*~flip(diag(ones(2,1),-1),2);
% toeplitz creats Toeplitz matrix from the vector.
% ones creats matrix of 2 rows of the number 1
% diag makes a diagonal matrix of the ones and the -1 difelects it diagonaly downwards.
%flip function switches the columns
% .* array multiplication

B = [M magic(3);magic(3)' rot90(M,2)]
% In the squre brrackets we combine all 4 matrix (3x3) to one big matrix (6x6). 
%rot90 rotates the matrix 90 degrees counter clockwise
