//- start porting SRs - more generic from AC!

// but also now becomes a list here...

/*

Implement/compare also these ones:

1- Turing Machine: cycle bit if noise vs. comp > than X, otherwise invert cycling bit

so goes from probability - all flips to no flips

// so we can get probability from: SR (x bits are 1), SR DAC (x bits),
// CV in as comparator for SR DAC, CV as comparator for ADC in, ADC as
// comparator for SR DAC -- DAC routing for this


2- Rungler: XOR out/cycling of SR with input bit [in benjolin the DAC out effects
freq of 2 oscs into both clock and as input bit - 2 offset
oscillators] eg. DAC effects speed/clock of SR

// complex: so one SR (osc) speed is determined by another one's DAC, with entry from
// that SR XOred with our cycling bit but this needs syncing across
// modes or we just leave it open...  input bit is bit routed in...
// special routing options

SR1->2(speed+offset)->SR1(incoming bit XOR with cycling bit)
   ->3(speed+offset)->SR1(speed)

eg. SRX has routing tables for speeds, SR1 as NSR->RSR/LSR->CSR (speed and bit)


3- Wiard noise ring: noise/comp selects new input or loop back/inverted loop back (jumper)

// same comp/probability options as TM

4- CGS(gated comparator - cgs313): This new "digital" input is OR gated with the original "analog" input,

comped in is ORed with looping bit - also bit for loop enable/disable

// comp options a bit simpler if any -> entry bit, ADC bit, pulsin bits

5- Electronotes wheel thing: LFSR SR bit is loaded/not loaded onto recycling SR. loading can be random (based on LFSR and set of probability switches)

LFSR is 24 stages long. recycling SR is 16 stages

// again probabilities which we can select with CV or pulses...

Others: 

6- Triadex Muse: set parity switches - sequences incoming to 31 bit SR

so there are 4 parity bits (theme slide) - selected from 32 bits of SR or clock bits (here is the difference)

if there is even number 1s on 4 sliders - recycled bit is a zero, if odd = a 1 

SO - this is an XOR of 4 bits - selected from clocking bits, on/off bit and from shift register feedback

// so how could other SR which feed into this one generate more on/off clocked rhythmic signals?

7++ - alternative implemnentations from AC

++ simple cycling SR as mode 0 and experimental parallel etc. SR in SR

++ self-routing SRs

*/

// but also implementations will change depending on routing/coggs
// all comes down to parity(eg 32 for cycling bit) and logical operation
