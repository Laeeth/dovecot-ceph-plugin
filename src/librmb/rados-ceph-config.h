// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
/*
 * Copyright (c) 2017 Tallence AG and the authors
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software
 * Foundation.  See file COPYING.
 */
#ifndef SRC_LIBRMB_RADOS_CEPH_CONFIG_H_
#define SRC_LIBRMB_RADOS_CEPH_CONFIG_H_

#include "rados-storage.h"
#include "rados-ceph-json-config.h"
#include "rados-types.h"
namespace librmb {

class RadosCephConfig {
 public:
  RadosCephConfig(RadosStorage *storage_);
  virtual ~RadosCephConfig() {}

  // load settings from rados cfg_object
  int load_cfg();
  int save_cfg();

  void set_storage(RadosStorage *storage_) { storage = storage_; }
  bool is_config_valid() { return config.is_valid(); }
  void set_config_valid(bool valid_) { config.set_valid(valid_); }
  bool is_user_mapping() { return !config.get_user_mapping().compare("true"); }
  void set_user_mapping(bool value_) { config.set_user_mapping(value_ ? "true" : "false"); }
  void set_user_ns(std::string &ns_) { config.set_user_ns(ns_); }
  std::string get_user_ns() { return config.get_user_ns(); }
  void set_user_suffix(std::string &ns_suffix_) { config.set_user_suffix(ns_suffix_); }
  std::string get_user_suffix() { return config.get_user_suffix(); }
  const std::string &get_public_namespace() const { return config.get_public_namespace(); }
  void set_public_namespace(std::string &public_namespace_) { config.set_public_namespace(public_namespace_); }

  void set_cfg_object_name(std::string cfg_object_name_) { config.set_cfg_object_name(cfg_object_name_); }
  std::string get_cfg_object_name() { return config.get_cfg_object_name(); }
  RadosCephJsonConfig *get_config() { return &config; }

  bool is_valid_key_value(std::string &key, std::string &value);
  bool update_valid_key_value(std::string &key, std::string &value);

  bool is_mail_attribute(enum rbox_metadata_key key) { return config.is_mail_attribute(key); }
  bool is_updateable_attribute(enum rbox_metadata_key key) { return config.is_updateable_attribute(key); }
  bool is_update_attributes() { return config.is_update_attributes(); }

  void update_mail_attribute(const char *value) { config.update_mail_attribute(value); }
  void update_updateable_attribute(const char *value) { config.update_updateable_attribute(value); }

  const std::string &get_mail_attribute_key() { return config.get_mail_attribute_key(); }
  const std::string &get_updateable_attribute_key() { return config.get_updateable_attribute_key(); }
  const std::string &get_update_attributes_key() { return config.get_update_attributes_key(); }

 private:
  RadosCephJsonConfig config;
  RadosStorage *storage;
};

} /* namespace tallence */

#endif /* SRC_LIBRMB_RADOS_CEPH_CONFIG_H_ */