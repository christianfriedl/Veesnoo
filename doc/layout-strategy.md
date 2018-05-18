# general points

* we probably do not need different "managers"
* a Container should have a Layouter, or LayoutEngine, or similar...
* for starters, we have a fixed association between
    * a Container
    * a Layouter
    * a FocusManager...
* layout is always done outside to inside
* layout is deterministic, there is no fancy optimization algo
    

# general layout strategy

* from least to most important
    * rectangle given by the user/widget
    * hints given by the user/widget (maximize-horizontal, align-left, align-top)
    * relation to other elements (left-of xxx)
    * order of elements, weight
    * min-dimensions
    * constraints from parent



# an example

* parent window: 0, 0, 50, 20
* el1: 0, 0, 10, 10, maximize-horizontal, maximize-vertical, min: 10, 3, weight: 0
* el2: 0, 0, 10, 10, maximize-horizontal, maximize-vertical, min: 10, 3, weight: 100, south-of(el1)
* el3: 0, 0, 10, 10, maximize-horizontal, maximize-vertical, min: 10, 3, south-of(el2), weight: 5

+---------+---------+--------+---------+----------+
|+el1--------------------------------------------+|
||                                               ||
|+-----------------------------------------------+|
|+el2--------------------------------------------+|
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
||                                               ||
|+-----------------------------------------------+|
|+el3--------------------------------------------+|
||                                               ||
|+-----------------------------------------------+|
+---------+---------+--------+---------+----------+
