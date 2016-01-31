#include <rl/util/Timer.h>
#include <rl/plan/SimpleModel.h>

#include "YourSampler.h"

YourSampler::YourSampler() :
  Sampler(),
  rand(
    ::boost::mt19937(static_cast< ::boost::mt19937::result_type >(::rl::util::Timer::now() * 1000000.0f)),
    ::boost::uniform_real< ::rl::math::Real >(0.0f, 1.0f)
    )
{
}

YourSampler::~YourSampler()
{
}

void
YourSampler::generate(::rl::math::Vector& q)
{
  assert(q.size() == this->model->getDof());

  //get the minimal and maximal joint limits
  ::rl::math::Vector maximum(this->model->getDof());
  this->model->getMaximum(maximum);
  ::rl::math::Vector minimum(this->model->getDof());
  this->model->getMinimum(minimum);

  //for each dimension draw a random sample from interval [minimum, maximum]
  for (::std::size_t i = 0; i < this->model->getDof(); ++i)
  {
    q(i) = minimum(i) + this->rand() * (maximum(i) - minimum(i));
  }
}

void
YourSampler::seed(const ::boost::mt19937::result_type& value)
{
  this->rand.engine().seed(value);
}

