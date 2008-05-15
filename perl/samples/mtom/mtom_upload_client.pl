#!/usr/bin/env perl

# Copyright 2005,2006 WSO2, Inc. http://wso2.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and

use WSO2::WSF;

# This sample upload an image to a service hosted with WSF/PHP assuming
# you have installed WSF/PHP on your machine and all the samples can be accessed from
# http://localhost/samples

my $payload =<<X;
<ns1:upload xmlns:ns1="http://php.axis2.org/samples/mtom">
  <ns1:fileName>test.jpg</ns1:fileName>
  <ns1:image xmlmime:contentType="image/jpeg" xmlns:xmlmime="http://www.w3.org/2004/06/xmlmime">
    <xop:Include href="cid:myid1" xmlns:xop="http://www.w3.org/2004/08/xop/include" />
  </ns1:image>
</ns1:upload>
X

my $client = new WSO2::WSF::WSClient(
    { 'wsfc_home' => '/opt/wso2/wsf_c',
      'to'        => 'http://localhost/samples/mtom/mtom_upload_service_base64.php',
      'useMTOM'   => 'FALSE' } );

open FILE, "< axis2.jpg";
undef $/;
my $contents = <FILE>;

my $msg = new WSO2::WSF::WSMessage( { 'payload' => $payload,
				      'attachments' => {"myid1" => $contents} } );

my $res = $client->request( $msg );
