/*
 * Copyright 2009, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


// Mac aggregator, which aggregates counters to a keyvaluetable. It is the
// interface to the keyvaluetable for all clients.

#ifndef O3D_STATSREPORT_AGGREGATOR_MAC_H__
#define O3D_STATSREPORT_AGGREGATOR_MAC_H__

#include <Cocoa/Cocoa.h>

#include <string>
#include "statsreport/aggregator.h"
#include "base/scoped_ptr.h"

namespace stats_report {

class Formatter;

class MetricsAggregatorMac: public MetricsAggregator {
 public:
  // @param coll the metrics collection to aggregate, most usually this
  //           is g_global_metrics.
  explicit MetricsAggregatorMac(const MetricCollection &coll);
  virtual ~MetricsAggregatorMac();


 protected:
  virtual bool StartAggregation();
  virtual void EndAggregation();

  virtual void Aggregate(CountMetric *metric);
  virtual void Aggregate(TimingMetric *metric);
  virtual void Aggregate(IntegerMetric *metric);
  virtual void Aggregate(BoolMetric *metric);

 private:
  NSAutoreleasePool *pool_;
  NSMutableDictionary *dict_;
  NSString *storePath_;

  DISALLOW_COPY_AND_ASSIGN(MetricsAggregatorMac);
};

}  // namespace stats_report

#endif  // O3D_STATSREPORT_AGGREGATOR_MAC_H__
