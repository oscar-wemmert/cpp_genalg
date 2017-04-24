~~~USAGE~~~
compile all .cpp files in folder src:
cd src && gcc -o genalg *.cpp 
or equivalent

The program supports two parameters, printLevel and generations.
At printlevel 0 the program produces no output at all.
At printlevel 1 (default) the program displays the best initial
and best final fitness, as well as the improment and the
final path.
At printlevel 2 the program also prints the fitness of the best
individual in each generation.
Default generations is 10 000.
examples:
	genalg 2 100
	genalg 1 20000
	genalg   <- is the same as genalg 1 10000

~~~Classes~~~
Genome: 
	Contains the population of chromosomes,	has functions
	to CalcPopFitness (using a domain) of the population,
	sort the population, and so on.
Domain
	Contains a problem domain, in this case TSP.	
CityGrid : Domain
	Contains cities, randomly created as Point2d:s with
	x between 0 and MAX_X, same with y. Has a CalcFitness
	that takes a chromosome and sets its mFitness.
Chromosome:
	Container for genes and some info like fitness.
Selector:
	Base class for creating new generations, contains
	a Mutator and a Crosser. Derived classes need to
	implement SelectN.
RouletteSelector : Selector
	SelectN returns according to the Roulette teqnique.
Mutator:
	Base class for mutations, in this this class is used.
Crosser:
	Class that takes two chromsomes, and returns two new ones
	that have been crossed in some way.
TwoPointCrossover : Crosser
	Returns according to twopointcrossover (multipoint)
Point2d (struct)
	Represents a point, with x and y.

~~~Notes~~~
Many files contain couts that have been commented out.
These can be used to see if certain parts of the program
work, but produce a lot of spam.