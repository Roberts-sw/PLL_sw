# pll_sw.py:
#	run a Tcl-script using Python IDLE, close the tk GUI and
#	expand or view the "Squeezed text"

# lines below act like:
#	1. generate a Tk-GUI to use Tcl in Python
#	2. call the Tcl-script, it has to end in setting a result
#	3. open the GUI and save the script result
#	4. print the result
#	5. (optional) run the Tk-GUI
import tkinter;     gui=tkinter.Tk()
script='pll_sw.tcl'
rc=gui.tk.eval(open(script,'r').read())
print(rc)
# gui.mainloop()
