# SiLi
A simple and basic linear algebra library for c++ using little code.

The best part is: 
It's all contained within a single header file and does not depend ony any 3rd party library. 

# Features
* Compile time matrix size checking
* no new/delete/malloc/free usage
* exchangable datatypes
* Matrix operations:
  * Matrix operations: multiplikation, addition, substraction, negation, assignment
  * Element wise operations: multiplikation, assignment
  * views on matrices
  * determinant
  * inverse()
  * norm()
  * normalize()
  * svd decomposition
  * transpose (as a view)
  * diagnoal acces (as a view)
  * iteration over elements, rows or columns possible
  * join_rows()/join_cols()
  * isfinite()
  * abs()
  * sum()
  * cross() for 3x1 Matrices
* Quaternion operations:
  * conversion from/to matrices
  * multipikation, addition, substracton
  * img(), real()
  * norm()
  * normalize()
  * conjugate()
  * dot()
  * slerp()
  * rotate()
  * computation of minimal rotation between two vectors
