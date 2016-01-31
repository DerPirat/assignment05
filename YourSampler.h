#ifndef _YOURSAMPLER_H_
#define _YOURSAMPLER_H_

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

#include <rl/plan/Sampler.h>

class YourSampler : public rl::plan::Sampler
{
public:
  YourSampler();

  virtual ~YourSampler();

  void generate(::rl::math::Vector& q);

  virtual void seed(const ::boost::mt19937::result_type& value);

protected:
  ::boost::variate_generator< ::boost::mt19937, ::boost::uniform_real< ::rl::math::Real > > rand;

private:

};


#endif // _YOURSAMPLER_H_
