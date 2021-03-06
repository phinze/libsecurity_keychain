/*
 * Copyright (c) 2006-2009 Apple Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*!
	@header SecCertificate
	The functions provided in SecCertificate.h implement and manage a
    particular type of keychain item that represents a X.509 public key
    certificate. You can store a certificate in a keychain, but a
    certificate can also be a transient object.

	You can use a certificate as a keychain item in most functions.
*/

#ifndef _SECURITY_SECCERTIFICATEP_H_
#define _SECURITY_SECCERTIFICATEP_H_

#include "SecBaseP.h"
#include <CoreFoundation/CFData.h>

#if defined(__cplusplus)
extern "C" {
#endif

/*!
	@function SecCertificateGetTypeIDP
	@abstract Returns the type identifier of SecCertificate instances.
	@result The CFTypeID of SecCertificate instances.
*/
CFTypeID SecCertificateGetTypeIDP(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/*!
	@function SecCertificateCreateWithDataP
	@abstract Create a certificate given it's DER representation as a CFData.
    @param allocator CFAllocator to allocate the certificate with.
    @param certificate DER encoded X.509 certificate.
	@result Return NULL if the passed-in data is not a valid DER-encoded
    X.509 certificate, return a SecCertificateRef otherwise.
*/
SecCertificateRefP SecCertificateCreateWithDataP(CFAllocatorRef allocator,
    CFDataRef data) __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_2_0);

/*!
	@function SecCertificateCopyDataP
	@abstract Return the DER representation of an X.509 certificate.
    @param certificate SecCertificate object created with
    SecCertificateCreateWithDataP().
	@result DER encoded X.509 certificate.
*/
CFDataRef SecCertificateCopyDataP(SecCertificateRefP certificate)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_2_0);

/*!
	@function SecCertificateCopySubjectSummary
	@abstract Return a simple string which hopefully represents a human
    understandable summary.
    @param certificate SecCertificate object created with
    SecCertificateCreateWithDataP().
    @discussion All the data in this string comes from the certificate itself
    and thus it's in whatever language the certificate itself is in.
	@result A CFStringRef which the caller should CFRelease() once it's no
    longer needed.
*/
CFStringRef SecCertificateCopySubjectSummaryP(SecCertificateRefP certificate)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_2_0);

#if defined(__cplusplus)
}
#endif

#endif /* !_SECURITY_SECCERTIFICATEP_H_ */
