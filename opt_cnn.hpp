#pragma once
#include"CNN/canela.hpp"

#if(0)
// These three macros are useful for tracing accesses.  See
// `example/stabilize.cpp` for an example of how to use them.
#define DUMP_ACCESS(t,x,y,z,b) do {					\
		trace << t.linearize(x,y,z,b) << " "			\
		      << " "						\
		      << &t.get(x,y,z,b) << " ";			\
	} while(0)

#define END_TRACE_LINE() do {trace << "\n";}while(0)
#define OPEN_TRACE(filename)  std::fstream trace; trace.open (filename, std::fstream::out);


// This one is customized for the stabilization code.  It prints out
// the linear index and address of each tensor element that's
// accessed.
#define DUMP_ACCESSES() do {\
		DUMP_ACCESS(in, i,b,0,0); \
		DUMP_ACCESS(weights, i,n,0,0);\
		DUMP_ACCESS(activator_input, n, 0,0, b); \
		END_TRACE_LINE();			 \
	} while(0)
#else
// By default, you get these versions, which do nothing.
#define DUMP_ACCESS(t,x,y,z,b)
#define END_TRACE_LINE
#define OPEN_TRACE(filename)
#define DUMP_ACCESSES()
#endif


// This class replaces its parent classes in the implementation of the learning
// model for this lab.  If you override functions in the baseclass by
// implementing them here, then the code here will run instead of the baseclass
// code.
//
// You should copy the functions you want to optimize into these classes, and
// confirm that the correctness tests pass.  Then, you can start modifying them
// to make them faster.
//
// The source code Canela is in /course/CSE141pp-SimpleCNN/CNN
class opt_fc_layer_t : public fc_layer_t
{
public:
	opt_fc_layer_t( tdsize in_size,
			int out_size ) : fc_layer_t(in_size, out_size) {

	}

};

class opt_conv_layer_t: public conv_layer_t
{
public:
	
	opt_conv_layer_t( uint16_t stride,
			  uint16_t kernel_size, 
			  uint16_t kernel_count,
			  double pad,
			  tdsize in_size
			  ) : conv_layer_t(stride, kernel_size, kernel_count, pad, in_size){}
};

class opt_pool_layer_t: public pool_layer_t
{
public:
	opt_pool_layer_t( uint16_t stride,
			  uint16_t filter_size,
			  double pad,
			  tdsize in_size ) : pool_layer_t(stride, filter_size, pad, in_size){}
};

class opt_relu_layer_t : public relu_layer_t
{
public:
	opt_relu_layer_t(const tdsize & in_size )
		:
		relu_layer_t(in_size)
	{
	}
};
