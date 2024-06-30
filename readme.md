# Financial Numerical Recipes in C++

Zip file with code for the manuscript "Financial Numerical Recipes in C++"

The code is in the two subdirectories:

```
all_cc_progs/: Code to create library
examples_cc/: Examples of library use, the same examples that are contained in the manuscript
```

The subdirectory  "all_cc_progs/" contains the source codes for the routines, with a makefile that will compile all the c++ files and put them into the library "librecipes.a" To make, cd into the directory and do "make lib"

The resulting library, contained in "librecipes.a", need to be copied into the "examples_cc" directory.
After that, run the examples by cd'ing to that directory and do "make run"

## run_all_examples

```
----------------------------
Present Value and Bond Pricing Chapter 
----------------------------
 present value, 5% discretely compounded interest = 9.29705
 internal rate of return = 0.1
 Bond price, 9% discretely compounded interest = 102.531
 bond yield to maturity = 0.09
 bond duration  = 1.01159
 bond duration modified = 2.5128
 bond convexity =8.93248
--------------------------------------------
 Term structure of interest rates examples  
--------------------------------------------
 a 1 period spot rate of 0.05 corresponds to a discount factor of 0.951229
 a 2 period discount factor of 0.9 corresponds to a spot rate of 0.0526803
 the forward rate between 1 and 2 is 0.0553605 using discount factors 
  and is 0.0553605 using yields 
discount factor t1 = 1:0.951229
discount factor t2 = 2:0.904837
spot rate t = 1:0.05
spot rate t = 2:0.05
forward rate from t1= 1 to t2= 2:0.05
 yields at times: 
 t=.1 0.1
 t=0.5 0.2
 t=1 0.3
 t=3 0.35
 t=5 0.4
 t=10 0.5
discount factor t1 = 1:0.932394
discount factor t2 = 2:0.865022
spot rate t = 1:0.07
spot rate t = 2:0.0725
forward rate from t1= 1 to t2= 2:0.075
 price = 99.1088
 duration = 1.9087
 convexity = 3.72611
---------------------------
Futures/Forwards pricing   
---------------------------
 futures price = 105.127
----------------------------
Binomial Chapter 
----------------------------
 one period european call =  3.64342
 two period european call =  35.4993
----------------------------------------
Examples in Black Scholes chapter 
----------------------------------------
 Black Scholes call price = 5.45325
 Option price partial derivatives, call option using Black Scholes 
  Delta = 0.633737
  Gamma = 0.0354789
  Theta = -6.61473
  Vega  = 13.3046
  Rho   = 13.1168
 Black Scholes implied volatility using Newton search = 0.0500427
 Black Scholes implied volatility using bisections = 0.0500414
-------------------------------
Black Scholes extensions
-------------------------------
 european stock call option with contininous dividend = 11.7344
 european stock call option with discrete dividend =  11.8094
 european futures call option = 0.851476
 european currency call option = 2.22556
 american call price with one dividend = 10.0166
 perpetual call price = 19.4767
-------------------------------------
Binomial Approximations examples
-------------------------------------
 european call = 14.9505
 american call = 14.9505
 Call price partials 
  delta = 0.699792
  gamma = 0.0140407
  theta = -9.89067
  vega  = 34.8536
  rho   = 56.9652
 call price with continuous dividend payout = 13.5926
 call price with proportial dividend yields at discrete dates = 11.8604
 call price with proportial dividend amounts at discrete dates = 12.0233
 european futures call option = 5.74254
 european currency option call = 2.23129
----------------------------------------
Warrant pricing chapter
----------------------------------------
 warrant price = 10.142
--------------------------
 Simulation examples 
--------------------------
 call:  black scholes price = 14.9758
        simulated price     = 14.928
 put:  black scholes price = 5.45954
       simulated price     = 5.5056
 call: bs delta  = 0.700208       sim delta = 0.697758
 put: bs delta  = -0.299792      sim delta = -0.281294
Black Scholes call option price = 14.9758
Simulated call option price     = 14.9425
Black Scholes put option price  = 5.45954
Simulated put option price      = 5.42098
Black Scholes call option price = 14.9758
Simulated call option price     = 14.9485
Simulated call option price, CV = 14.9758
Simulated call option price, AV = 14.9255
Black Scholes put option price  = 5.45954
Simulated put option price      = 5.4553
Simulated put option price,  CV = 5.42993
Simulated put option price,  AV = 5.42445
 cash or nothing, Q=1: 0.543807
 control_variate -0.100506
 antithetic_variate 0.550232
 asset or nothing: 69.8149
 control_variate 70.3699
 antithetic_variate 70.1418
----------------------------
Finite Differences examples 
----------------------------
 explicit finite differences, european put price = 4.03667
 explicit finite differences, american put price = 4.25085
------------------------------------
Approximations chapter 
------------------------------------
 Call price using Barone-Adesi Whaley approximation = 5.74339
-----------------------------
Alternative formulas 
-----------------------------
 Merton Jump diffusion call = 23.2074
------------------------------------
Average and Lookback Options 
------------------------------------
 Bermudan put price = 15.8869
 Analytical geometric average = 5.3562
 Lookback call price = 27.0713
Testing general simulation of European options 
 simulated arithmetric average  S= 100 r= 0.1 price=1.5803
 simulated geometric average = 1.3839
 analytical lookback put = 16.2665
 simulated lookback put = 15.2012
 analytical lookback call = 22.8089
 simulated lookback call = 22.2442
 simulated lookback call using control variates = 22.0499
---------------------------------------
Bond option pricing, simple (GBM) case 
---------------------------------------
 zero coupon put option price = 1.92791
 coupon bond put option price = 2.22852
 zero coupon american put option price, binomial = 2.43282
----------------------------
Further term structure models 
----------------------------
Example calculations using the Nelson Siegel term structure approximation
 direct calculation, yield = 0.0363142
 using a term structure class
 yield (t=1) = 0.0363142
 discount factor (t=1) = 0.964337
 forward rate (t1=1, t2=2) = 0.0300602
Example calculations using the Cox Ingersoll Ross term structure model 
 direct calculation, discount factor (t=1): 0.951166
 using a class 
 yield (t=1) = 0.0500668
 discount factor (t=1) = 0.951166
 forward (t1=1, t2=2) = 0.0498756
Example term structure calculations using a cubic spline 
 direct calculation, discount factor (t=1) 1.1
 Using a term structure class 
 yield (t=1) = -0.0953102
 discount factor (t=1) = 1.1
 forward (t1=1, t2=2) = 0.318454
Example term structure calculation using the Vasicek term structure model
 direct calculation, discount factor (t=1): 0.955408
 using a term structure class 
 yield (t=1) = 0.0456168
 discount factor (t=1) = 0.955408
 forward rate (t1=1, t2=2) = 0.0281476
---------------------------------------
Binomial term structure examples 
---------------------------------------
 Rendleman Bartter price of option on zero coupon bond:  c = 0.00713661
--------------------------------------
 term structure derivatives examples  
--------------------------------------
 Vasicek call option price 0.000226833
----------------------------------
 Normal distribution calculations 
----------------------------------
 N(0) = 0.5
 N(0,0,0) = 0.25
 5 random uniform numbers between 0 and 1:  0.849131 0.337019 0.270059 0.87726 0.105062
 5 random normal(0,1) numbers:  0.698069 -0.115685 -1.26145 -1.66461 1.4814
```

## Build and Package

```
mkdir build
cd build
cmake ..
make
make install
cpack

```

This will generate a package (e.g., a** **`.tar.gz` file or** **`.zip` file) that includes the** **`run_all_examples` executable, the** **`libfinance.a` library, the** **`libnewmat.a` library, and the necessary headers.

## Distribution

The generated package can be distributed and used on other systems. Recipients can extract the package and find the executables in the** **`bin` directory, the libraries in the** **`lib` directory, and the headers in the** **`include` directory.

There is a single file which include the archive embedded to distribute,

MacOS:

```
finance-1.0-Darwin.sh
```

Windows

```

```

Linux

```

```
