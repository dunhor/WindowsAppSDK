﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// THIS FILE IS AUTOMATICALLY GENERATED; DO NOT EDIT IT

// INPUT FILE: dev\common\TerminalVelocityFeatures-OAuth.xml
// OPTIONS: -Channel Experimental -Language C++ -Namespace Microsoft.Windows.Security.Authentication.OAuth -Path dev\common\TerminalVelocityFeatures-OAuth.xml -Output dev\common\TerminalVelocityFeatures-OAuth.h

#if defined(__midlrt)
namespace features
{
    feature_name Feature_OAuth = { DisabledByDefault, FALSE };
}
#endif // defined(__midlrt)

// Feature constants
#define WINDOWSAPPRUNTIME_MICROSOFT_WINDOWS_SECURITY_AUTHENTICATION_OAUTH_FEATURE_OAUTH_ENABLED 1

#if defined(__cplusplus)

namespace Microsoft::Windows::Security::Authentication::OAuth
{

__pragma(detect_mismatch("ODR_violation_WINDOWSAPPRUNTIME_MICROSOFT_WINDOWS_SECURITY_AUTHENTICATION_OAUTH_FEATURE_OAUTH_ENABLED_mismatch", "AlwaysEnabled"))
struct Feature_OAuth
{
    static constexpr bool IsEnabled() { return WINDOWSAPPRUNTIME_MICROSOFT_WINDOWS_SECURITY_AUTHENTICATION_OAUTH_FEATURE_OAUTH_ENABLED == 1; }
};

} // namespace Microsoft.Windows.Security.Authentication.OAuth

#endif // defined(__cplusplus)
