/*
 * Copyright 2020 The Fxt authors.
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#pragma once

#include <string>
#include <vector>

#include "sdm.hpp"

#include "fxt/doc_entry.hpp"
#include "fxt/forward_index.hpp"
#include "fxt/inverted_index.hpp"
#include "fxt/lexicon.hpp"
#include "fxt/query_train_file.hpp"

/**
 * Score SDM with the default parameters over entire documents.
 */
class DocSdmFeature {
  /**
   * The score for the current query-document pair.
   */
  double score_ = 0.0;

  /**
   * The SDM scoring function.
   */
  Sdm sdm_;

 public:
  /**
   * Construtor.
   */
  DocSdmFeature(Sdm &sdm) : sdm_(sdm) {}

  /**
   * Score query-document using SDM.
   */
  void compute(query_train &query, doc_entry &dentry, Document &document,
               Lexicon &lexicon, ForwardIndex &fwdidx, InvertedIndex &invidx) {
    score_ = sdm_.extract(query, document, lexicon, fwdidx, invidx);
    dentry.sdm = score_;
  }
};
