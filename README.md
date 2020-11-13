# PLL_sw
simulate a PLL in software

When having some interrupt frequency in your application and wanting
to have a counter that counts in milliseconds for convenience you
can easily simulate a PLL in software to address part of the problem.

The example presented here uses a hypothetical interrupt frequency of
256 Hz to arrive at a counter keeping track of ms.
