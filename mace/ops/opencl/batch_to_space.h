// Copyright 2018 Xiaomi, Inc.  All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MACE_OPS_OPENCL_BATCH_TO_SPACE_H_
#define MACE_OPS_OPENCL_BATCH_TO_SPACE_H_

#include <vector>

#include "mace/core/types.h"
#include "mace/public/mace.h"
#include "mace/utils/utils.h"

namespace mace {

class OpContext;
class Tensor;

namespace ops {
class OpenCLBatchToSpaceKernel {
 public:
  virtual MaceStatus Compute(
      OpContext *context,
      const Tensor *batch_tensor,
      const std::vector<int> &paddings,
      const std::vector<int> &block_shape,
      const std::vector<index_t> &output_shape,
      Tensor *space_tensor) = 0;
  MACE_EMPTY_VIRTUAL_DESTRUCTOR(OpenCLBatchToSpaceKernel);
};

}  // namespace ops
}  // namespace mace

#endif  // MACE_OPS_OPENCL_BATCH_TO_SPACE_H_
