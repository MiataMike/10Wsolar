# 10Wsolar
![image of charger](Http://michael-turner.ee/images/Dash.jpg)
This project is a solar power converter for charging the 12V battery in my truck with a 10W solar panel I got from amazon. 
## MPPT control
Solar panels deliver different currents at different voltages, in the specs below we can see it's 0A @ 21V and .57A @ 17.5V.
 The power of the first is 0W and the second is 10W, so we can get more power from our panel if we operate at the optimal voltage.
 The microcontroller will vary the duty cycle of the buck converter, lowering the voltage of the panel from between open circuit voltage and the battery's voltage.
 Additionally, I don't want to overcharge the battery (It's currently directly connected and who knows what rate it's working at) so I'll add some control logic to trickle charge the battery.
 Since I'm a data geek, I've added an SD card so I can monitor the panel's performance over time, and the truck's (hopefully full) state of charge.
 # Parts
 
 ## Voltage sensing
 The voltage sensing is reading the panel's voltage and the battery's voltage. The panel voltage is used in the control loop to calculate the power we're pulling from the panel. The battery voltage is measured to check state of charge.
 I've used high value resistors because this current draw is constant, even at night. The filtering is agressive so I'll need to slow down my control loop and watch out for oscillation.

 ## CPU
 I've wanted to get my feet wet with ARM processors after taking a class on them in college. This processor has a small form factor and low power to boost efficiency.
 
## Buck converter
Thanks TI for making the buck converter component datasheet! I've chosen values from the panel specs below, but added a much larger inductor in case my frequency needs to go down, or I want to convert much smaller currents
I've added a backup diode in case the syncronous switching doesn't work out. 
 
## current sensing
TI also makes a great chip for monitoring the voltage across a shunt. Doing this with a single ended ADC would be a pain, and it comes with built in filtering and gain. 

## 3.3V converter
Thanks Collin Winans, I'm using his design for a 3.3V buck converter to supply power to the circuit. Most of the symbols in this design are his too.
This should be a very efficeint option since we're stepping down all the way from 12V, which would be a lot of energy to burn in a linear regulator.

## MPPT algorithm
At first, I may just close the top switch and collect data on what the panel does when it's connected directly. This would give me a baseline
From there, I would write code that calculates and optimizes the power coming from the panel. 
The hill climbing algorithm that changes direction every time it detects a drop in power should do nicely. 
Some other features I'd like to add are:
- sleeping at night
- characterizing the panel (V vs A)
- voltage cutoff and derating based on battery voltage
- bitcoin mining to prevent overcharge (not on a Cortex-F0, but still)

## panel specs
- 21V open circuit
- 17.5V @peak power
- .57A 	@peak power
- stylish aluminum frame


# Routing considerations

## Current carrying
I'm designing this around a 1A nominal current, which is more than the 10W panel should put out on the 12V bus. Using a trace width calculator w/ 10C rise @ 1oz/ft^2, I get 11mil traces minimum. Lower trace resistance decreases losses, so this is a minimum

## Overall layout
when designing power electronics, it's important to imagine the current path and ground returns. Can you tell which way I routed it?

## Coil placement
 Big Bob is on the top, a horizontally mounted toroidal coil. On the bottom there's a bobbin wound inductor for the 5V supply.
 The direction of the magnetic field around the bobbin creates a toroid whose axis is normal to the board while the toroid creates a field in a circle along the plane of the board.
 Having these fields at 90 degrees should minimize coupling.

