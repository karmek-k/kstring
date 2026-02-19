# kstring

String implementation according to the Samsung R&amp;D Institute Poland C++ Tech Guide. 

## Requirements

* Do not use elements from the standard library.
* The class should be able to create an object based on a passed string constant.
  * implemented - also includes constructors and assignment operators for copy & move semantics
* The class should have a method that returns the length of the string.
  * implemented (`size()`)
* The class should have an index operator that returns the specified letter.
  * implemented (`operator[]`)
* The class should have an operator method that allows adding additional characters to the string.
* Stream operators should be defined that allow objects to be output to the screen or to a file.
