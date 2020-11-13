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
