# PLL_sw
simulate a PLL in software

When having some interrupt frequency in your application and wanting
to have a counter that counts in milliseconds for convenience you
can easily simulate a PLL in software to address part of the problem.

The example presented here uses a hypothetical interrupt frequency of
256 Hz to arrive at a counter keeping track of ms.

A simulation of the results is presented in Tcl, that can also be run
when Python is installed with the help of a Python script that uses
the built-in Tcl interpreter.
