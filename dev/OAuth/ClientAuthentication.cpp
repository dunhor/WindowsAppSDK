﻿#include <pch.h>
#include "common.h"

#include "ClientAuthentication.h"

#include <Microsoft.Windows.Security.Authentication.OAuth.ClientAuthentication.g.cpp>

using namespace winrt::Microsoft::Windows::Security::Authentication::OAuth;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Security::Cryptography;
using namespace winrt::Windows::Web::Http::Headers;

namespace winrt::Microsoft::Windows::Security::Authentication::OAuth::implementation
{
    ClientAuthentication::ClientAuthentication()
    {
        THROW_HR_IF(E_NOTIMPL, !::Microsoft::Windows::Security::Authentication::OAuth::Feature_OAuth::IsEnabled());
    }

    ClientAuthentication::ClientAuthentication(const HttpCredentialsHeaderValue& authorization) :
        m_authorization(authorization)
    {
        THROW_HR_IF(E_NOTIMPL, !::Microsoft::Windows::Security::Authentication::OAuth::Feature_OAuth::IsEnabled());
    }

    oauth::ClientAuthentication ClientAuthentication::CreateForBasicAuthorization(const winrt::hstring& clientId,
        const winrt::hstring& clientSecret)
    {
        auto authString = clientId + L":" + clientSecret;
        auto buffer = CryptographicBuffer::ConvertStringToBinary(authString, BinaryStringEncoding::Utf8);
        auto base64Token = CryptographicBuffer::EncodeToBase64String(buffer);
        HttpCredentialsHeaderValue header(L"Basic", base64Token);
        return winrt::make<ClientAuthentication>(header);
    }

    HttpCredentialsHeaderValue ClientAuthentication::Authorization()
    {
        std::shared_lock guard{ m_mutex };
        return m_authorization;
    }

    void ClientAuthentication::Authorization(const HttpCredentialsHeaderValue& value)
    {
        std::lock_guard guard{ m_mutex };
        m_authorization = value;
    }

    HttpCredentialsHeaderValue ClientAuthentication::ProxyAuthorization()
    {
        std::shared_lock guard{ m_mutex };
        return m_proxyAuthorization;
    }

    void ClientAuthentication::ProxyAuthorization(const HttpCredentialsHeaderValue& value)
    {
        std::lock_guard guard{ m_mutex };
        m_proxyAuthorization = value;
    }

    winrt::Windows::Foundation::Collections::IMap<hstring, hstring> ClientAuthentication::AdditionalHeaders()
    {
        std::shared_lock guard{ m_mutex };
        return m_additionalHeaders;
    }
}
