/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <keymaster/attestation_context.h>

#include <keymaster/contexts/soft_attestation_cert.h>

namespace keymaster {

class SoftAttestationContext : public AttestationContext {
  public:
    explicit SoftAttestationContext(KmVersion version) : AttestationContext(version) {}

    keymaster_security_level_t GetSecurityLevel() const override {
        return KM_SECURITY_LEVEL_SOFTWARE;
    }

    const VerifiedBootParams* GetVerifiedBootParams(keymaster_error_t* error) const override;

    KeymasterKeyBlob GetAttestationKey(keymaster_algorithm_t algorithm,
                                       keymaster_error_t* error) const override {
        return KeymasterKeyBlob(*getAttestationKey(algorithm, error));
    }

    CertificateChain GetAttestationChain(keymaster_algorithm_t algorithm,
                                         keymaster_error_t* error) const override {
        return getAttestationChain(algorithm, error);
    }
};

}  // namespace keymaster
