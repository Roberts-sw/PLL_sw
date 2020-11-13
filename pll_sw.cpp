/* pll_sw.cpp
parameters:
	ms         derived value from tick interrupts
	rem        interrupt accumulator / remainder
	const DIV  interrupt frequency
	const MUL  wanted ms count per second

routine:
	tick count in rem and derive ms from it through constants DIV and MUL

simulation: see pll_sw.tcl in comments below 	
*/
struct pll_sw
{	volatile unsigned ms, rem;
	unsigned const DIV=256;
	unsigned const MUL=1000;
} a;

void tick (void)
{	if( a.DIV <= (a.rem += a.MUL) )
	{	a.ms += a.rem/a.DIV;
		a.rem = a.rem%a.DIV;
	}
}

#if 0
{
# Tcl simulation of the C-code from pll_sw.c, 2 seconds of tick interrupts: 

# pll_sw.tcl
array set a {ms 0	rem 0	DIV 256	MUL 1000}
proc tick {} {global a
	if { $a(DIV) <= [incr a(rem) $a(MUL) ] } {
		incr a(ms) [expr {$a(rem)/$a(DIV)} ]
		set a(rem) [expr {$a(rem)%$a(DIV)} ]
	}
}

for {set i 0} {$i < $a(DIV) * 2} {incr i} {
	tick; append res "ms:$a(ms)\tacc:$a(rem)\r\n"
};	set res

}
#endif

#if 0
{
# to simulate in Python IDLE, save/run the script below as pll_sw.py
#	close the tk GUI and expand or view the "Squeezed text"

# pll_sw.py
import tkinter;     gui=tkinter.Tk()
script='pll_sw.tcl'
rc=gui.tk.eval(open(script,'r').read())
print(rc)
gui.mainloop()

}
#endif
