# ALAB
Another Linnear Algebra Benchmark is a benchmark closely inspired by the [HPCCG](https://github.com/Mantevo/HPCCG) benchmark. This project is on early development and there will be a roadmap bellow for future work. 

## Installation 
To install this program you need to make sure your compiler supports OpenMP. If it does support it proceed with the following commands: 

`git clone git@github.com:TolisSth/ALAB.git`

`cd ALAB`

`make clean`

`make -j`

## Usage 
In general the `--help` argument explains everything but because this is a `README.md` file let's plagiarize. 
```
Usage: alab [options]
Options:
  --size, -s <size>        Set the size (default: 1000)
  --threads, -t <num>      Set the number of threads (default: 2)
  --seed, -sd <seed>         Set the random seed (default: 42)
  --help, -h               Display this help message
  --serial                 Run the serial version of the benchmark (default)
  --parallel               Run the parallel version of the benchmark (please specify number of thread or else it will run in two threads)

```
This is the `--help` message and as it is evident you don't need to do much to run the program because it will handle the configuration by itself running the equal: `./alab --size 1000 --threads 2 --serial --seed 42`, which is a bit misleading since `--threads` are only used when the kernel is running at parallel but oh well, more thing to add to the roadmap. 

A good starting configuration to play with the parallel kernel is: 

`./alab --size 100000 --threads 8 --parallel`. 

## Roadmap 
The aforementioned roadmap is finally here! The whole roadmap is splitted in two categories, the infrastructure part and the kernels part namely: 

#### Infrastructure 
- [x] C++ Multitreading through OpenMP.
- [ ] MPI or [Chapel](https://chapel-lang.org/) support.
- [ ] A way for the user to extract the data in a data analysis ready format.

#### Kernels 
- [x] DDOT
- [ ] Gauss Elimination
- [ ] Sparse Matrix-Vector Multiplication 

## Contribute 
Hey! I don't bite and I am looking for people to work with me on this project so feel free to contact me or just fork the project and start writing your first pull request. 
