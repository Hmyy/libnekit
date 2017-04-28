// MIT License

// Copyright (c) 2017 Zhuhao Wang

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef NEKIT_STREAM_CODER_ERROR
#define NEKIT_STREAM_CODER_ERROR

#include <boost/asio.hpp>

#include <nekit/utils/error.h>

namespace nekit {
namespace stream_coder {

enum ErrorCode { kNoCoder = 0 };

class ErrorCategory : public std::error_category {
  virtual const char* name() const BOOST_NOEXCEPT override;
  virtual std::string message(int error_code) const override;
};

const ErrorCategory& error_category();
}  // namespace stream_coder
}  // namespace nekit

namespace std {
template <>
struct is_error_code_enum<nekit::stream_coder::ErrorCode>
    : public std::true_type {};

error_code make_error_code(nekit::stream_coder::ErrorCode errc) {
  return error_code(static_cast<int>(errc),
                    nekit::stream_coder::error_category());
}
}  // namespace std

#endif /* NEKIT_STREAM_CODER_ERROR */
