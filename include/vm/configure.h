//===-- ssvm/vm/configure.h - consiguration class of ssvm -----------------===//
//
// Part of the SSVM Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contents the configuration class.
///
//===----------------------------------------------------------------------===//
#pragma once

#include <memory>
#include <string>

namespace SSVM {
namespace VM {

class Configure {
public:
  /// VM type enum class.
  enum class VMType : unsigned int { Wasm = 0, EWasm, Wasi };

  Configure() = delete;
  Configure(VMType NewType = VMType::Wasm) : Type(NewType) {
    if (Type == VMType::EWasm) {
      StartFuncName = "main";
    } else if (Type == VMType::Wasi) {
      StartFuncName = "_main";
    }
  }
  ~Configure() = default;

  VMType getVMType() { return Type; }

  std::string &getStartFuncName() { return StartFuncName; }

  void setStartFuncName(const std::string &Name) { StartFuncName = Name; }

private:
  VMType Type;
  std::string StartFuncName;
};

} // namespace VM
} // namespace SSVM