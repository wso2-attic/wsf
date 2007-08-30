--TEST--
Test for RetArrayString1D_client_DocLitB sample
--FILE--

<?php

try {

    $client = new WSClient(
        array("wsdl"=>"tests/samples/misc_files/ComplexDataTypesDocLitB.wsdl" ,
              "useSOAP" => "1.1",
              "to" => "http://localhost/samples/DocLitB_Service.php"));
    $proxy = $client->getProxy();	
    
    $string1 = array(NULL);
    $val =  $proxy->RetArrayString1D($string1);
    echo "\n";
    var_dump($val);
    echo "\n";

/*     $string11 = array(NULL); */
    $val =  $proxy->RetArrayString1D();
    echo "\n";
    var_dump($val);
    echo "\n";

    $string2 = "One Element";
    $val =  $proxy->RetArrayString1D(array($string2));    
    
    echo "\n One Element \n ============\n";
    echo $val->string."\n";
    echo "\n";

    $string3 = array();
    for($i = 0; $i<10; $i++){
        $string3[$i] = "string Array Data".$i;
    }
    $val =  $proxy->RetArrayString1D($string3);
    echo "\n Ten Elements \n ============\n";
    foreach($val->string as $i=> $value){
        if($value)
            echo $value."\n";
        
    }
    echo "\n";

    $string3 = array();
    for($i = 0; $i<10; $i++){
        $string3[$i] =  NULL;
    }
    $val =  $proxy->RetArrayString1D($string3);
    echo "\n All ten NULL Elements \n =============\n";
    foreach($val->string as $i=> $value){
        if(!$value)
            echo $value."NULL value\n";
        
    }
    echo "\n";

    $string4 = array();
    for($i = 0; $i<10; $i++){
        if($odd = $i%2)
            $string4[$i] = "string Array Data".$i;
        else
            $string4[$i] = NULL;

    }
    $val =  $proxy->RetArrayString1D($string4);
    echo "\n Ten with NULL Elements \n =============\n";
    foreach($val->string as $i=> $value){
        if(!$value)
            echo $value."NULL value\n";
        else
            echo $value."\n";
    }
    echo "\n";

    $string5 = array();
    for($i = 0; $i<1000; $i++){
        $string5[$i] =  "string Array Data".$i;;
    }
    $val =  $proxy->RetArrayString1D($string5);
    echo "\n All ten NULL Elements \n =============\n";
    foreach($val->string as $i=> $value){
        if($value)
            echo $value."\n";
        
    }
    echo "\n";
        

} catch (Exception $e) {

		printf("Message = %s\n",$e->getMessage());
}
?>

--EXPECT--
object(stdClass)#3 (0) {
}


object(stdClass)#4 (0) {
}


 One Element 
 ============
One Element


 Ten Elements 
 ============
string Array Data0
string Array Data1
string Array Data2
string Array Data3
string Array Data4
string Array Data5
string Array Data6
string Array Data7
string Array Data8
string Array Data9


 All ten NULL Elements 
 =============
NULL value
NULL value
NULL value
NULL value
NULL value
NULL value
NULL value
NULL value
NULL value
NULL value


 Ten with NULL Elements 
 =============
NULL value
string Array Data1
NULL value
string Array Data3
NULL value
string Array Data5
NULL value
string Array Data7
NULL value
string Array Data9


 All ten NULL Elements 
 =============
string Array Data0
string Array Data1
string Array Data2
string Array Data3
string Array Data4
string Array Data5
string Array Data6
string Array Data7
string Array Data8
string Array Data9
string Array Data10
string Array Data11
string Array Data12
string Array Data13
string Array Data14
string Array Data15
string Array Data16
string Array Data17
string Array Data18
string Array Data19
string Array Data20
string Array Data21
string Array Data22
string Array Data23
string Array Data24
string Array Data25
string Array Data26
string Array Data27
string Array Data28
string Array Data29
string Array Data30
string Array Data31
string Array Data32
string Array Data33
string Array Data34
string Array Data35
string Array Data36
string Array Data37
string Array Data38
string Array Data39
string Array Data40
string Array Data41
string Array Data42
string Array Data43
string Array Data44
string Array Data45
string Array Data46
string Array Data47
string Array Data48
string Array Data49
string Array Data50
string Array Data51
string Array Data52
string Array Data53
string Array Data54
string Array Data55
string Array Data56
string Array Data57
string Array Data58
string Array Data59
string Array Data60
string Array Data61
string Array Data62
string Array Data63
string Array Data64
string Array Data65
string Array Data66
string Array Data67
string Array Data68
string Array Data69
string Array Data70
string Array Data71
string Array Data72
string Array Data73
string Array Data74
string Array Data75
string Array Data76
string Array Data77
string Array Data78
string Array Data79
string Array Data80
string Array Data81
string Array Data82
string Array Data83
string Array Data84
string Array Data85
string Array Data86
string Array Data87
string Array Data88
string Array Data89
string Array Data90
string Array Data91
string Array Data92
string Array Data93
string Array Data94
string Array Data95
string Array Data96
string Array Data97
string Array Data98
string Array Data99
string Array Data100
string Array Data101
string Array Data102
string Array Data103
string Array Data104
string Array Data105
string Array Data106
string Array Data107
string Array Data108
string Array Data109
string Array Data110
string Array Data111
string Array Data112
string Array Data113
string Array Data114
string Array Data115
string Array Data116
string Array Data117
string Array Data118
string Array Data119
string Array Data120
string Array Data121
string Array Data122
string Array Data123
string Array Data124
string Array Data125
string Array Data126
string Array Data127
string Array Data128
string Array Data129
string Array Data130
string Array Data131
string Array Data132
string Array Data133
string Array Data134
string Array Data135
string Array Data136
string Array Data137
string Array Data138
string Array Data139
string Array Data140
string Array Data141
string Array Data142
string Array Data143
string Array Data144
string Array Data145
string Array Data146
string Array Data147
string Array Data148
string Array Data149
string Array Data150
string Array Data151
string Array Data152
string Array Data153
string Array Data154
string Array Data155
string Array Data156
string Array Data157
string Array Data158
string Array Data159
string Array Data160
string Array Data161
string Array Data162
string Array Data163
string Array Data164
string Array Data165
string Array Data166
string Array Data167
string Array Data168
string Array Data169
string Array Data170
string Array Data171
string Array Data172
string Array Data173
string Array Data174
string Array Data175
string Array Data176
string Array Data177
string Array Data178
string Array Data179
string Array Data180
string Array Data181
string Array Data182
string Array Data183
string Array Data184
string Array Data185
string Array Data186
string Array Data187
string Array Data188
string Array Data189
string Array Data190
string Array Data191
string Array Data192
string Array Data193
string Array Data194
string Array Data195
string Array Data196
string Array Data197
string Array Data198
string Array Data199
string Array Data200
string Array Data201
string Array Data202
string Array Data203
string Array Data204
string Array Data205
string Array Data206
string Array Data207
string Array Data208
string Array Data209
string Array Data210
string Array Data211
string Array Data212
string Array Data213
string Array Data214
string Array Data215
string Array Data216
string Array Data217
string Array Data218
string Array Data219
string Array Data220
string Array Data221
string Array Data222
string Array Data223
string Array Data224
string Array Data225
string Array Data226
string Array Data227
string Array Data228
string Array Data229
string Array Data230
string Array Data231
string Array Data232
string Array Data233
string Array Data234
string Array Data235
string Array Data236
string Array Data237
string Array Data238
string Array Data239
string Array Data240
string Array Data241
string Array Data242
string Array Data243
string Array Data244
string Array Data245
string Array Data246
string Array Data247
string Array Data248
string Array Data249
string Array Data250
string Array Data251
string Array Data252
string Array Data253
string Array Data254
string Array Data255
string Array Data256
string Array Data257
string Array Data258
string Array Data259
string Array Data260
string Array Data261
string Array Data262
string Array Data263
string Array Data264
string Array Data265
string Array Data266
string Array Data267
string Array Data268
string Array Data269
string Array Data270
string Array Data271
string Array Data272
string Array Data273
string Array Data274
string Array Data275
string Array Data276
string Array Data277
string Array Data278
string Array Data279
string Array Data280
string Array Data281
string Array Data282
string Array Data283
string Array Data284
string Array Data285
string Array Data286
string Array Data287
string Array Data288
string Array Data289
string Array Data290
string Array Data291
string Array Data292
string Array Data293
string Array Data294
string Array Data295
string Array Data296
string Array Data297
string Array Data298
string Array Data299
string Array Data300
string Array Data301
string Array Data302
string Array Data303
string Array Data304
string Array Data305
string Array Data306
string Array Data307
string Array Data308
string Array Data309
string Array Data310
string Array Data311
string Array Data312
string Array Data313
string Array Data314
string Array Data315
string Array Data316
string Array Data317
string Array Data318
string Array Data319
string Array Data320
string Array Data321
string Array Data322
string Array Data323
string Array Data324
string Array Data325
string Array Data326
string Array Data327
string Array Data328
string Array Data329
string Array Data330
string Array Data331
string Array Data332
string Array Data333
string Array Data334
string Array Data335
string Array Data336
string Array Data337
string Array Data338
string Array Data339
string Array Data340
string Array Data341
string Array Data342
string Array Data343
string Array Data344
string Array Data345
string Array Data346
string Array Data347
string Array Data348
string Array Data349
string Array Data350
string Array Data351
string Array Data352
string Array Data353
string Array Data354
string Array Data355
string Array Data356
string Array Data357
string Array Data358
string Array Data359
string Array Data360
string Array Data361
string Array Data362
string Array Data363
string Array Data364
string Array Data365
string Array Data366
string Array Data367
string Array Data368
string Array Data369
string Array Data370
string Array Data371
string Array Data372
string Array Data373
string Array Data374
string Array Data375
string Array Data376
string Array Data377
string Array Data378
string Array Data379
string Array Data380
string Array Data381
string Array Data382
string Array Data383
string Array Data384
string Array Data385
string Array Data386
string Array Data387
string Array Data388
string Array Data389
string Array Data390
string Array Data391
string Array Data392
string Array Data393
string Array Data394
string Array Data395
string Array Data396
string Array Data397
string Array Data398
string Array Data399
string Array Data400
string Array Data401
string Array Data402
string Array Data403
string Array Data404
string Array Data405
string Array Data406
string Array Data407
string Array Data408
string Array Data409
string Array Data410
string Array Data411
string Array Data412
string Array Data413
string Array Data414
string Array Data415
string Array Data416
string Array Data417
string Array Data418
string Array Data419
string Array Data420
string Array Data421
string Array Data422
string Array Data423
string Array Data424
string Array Data425
string Array Data426
string Array Data427
string Array Data428
string Array Data429
string Array Data430
string Array Data431
string Array Data432
string Array Data433
string Array Data434
string Array Data435
string Array Data436
string Array Data437
string Array Data438
string Array Data439
string Array Data440
string Array Data441
string Array Data442
string Array Data443
string Array Data444
string Array Data445
string Array Data446
string Array Data447
string Array Data448
string Array Data449
string Array Data450
string Array Data451
string Array Data452
string Array Data453
string Array Data454
string Array Data455
string Array Data456
string Array Data457
string Array Data458
string Array Data459
string Array Data460
string Array Data461
string Array Data462
string Array Data463
string Array Data464
string Array Data465
string Array Data466
string Array Data467
string Array Data468
string Array Data469
string Array Data470
string Array Data471
string Array Data472
string Array Data473
string Array Data474
string Array Data475
string Array Data476
string Array Data477
string Array Data478
string Array Data479
string Array Data480
string Array Data481
string Array Data482
string Array Data483
string Array Data484
string Array Data485
string Array Data486
string Array Data487
string Array Data488
string Array Data489
string Array Data490
string Array Data491
string Array Data492
string Array Data493
string Array Data494
string Array Data495
string Array Data496
string Array Data497
string Array Data498
string Array Data499
string Array Data500
string Array Data501
string Array Data502
string Array Data503
string Array Data504
string Array Data505
string Array Data506
string Array Data507
string Array Data508
string Array Data509
string Array Data510
string Array Data511
string Array Data512
string Array Data513
string Array Data514
string Array Data515
string Array Data516
string Array Data517
string Array Data518
string Array Data519
string Array Data520
string Array Data521
string Array Data522
string Array Data523
string Array Data524
string Array Data525
string Array Data526
string Array Data527
string Array Data528
string Array Data529
string Array Data530
string Array Data531
string Array Data532
string Array Data533
string Array Data534
string Array Data535
string Array Data536
string Array Data537
string Array Data538
string Array Data539
string Array Data540
string Array Data541
string Array Data542
string Array Data543
string Array Data544
string Array Data545
string Array Data546
string Array Data547
string Array Data548
string Array Data549
string Array Data550
string Array Data551
string Array Data552
string Array Data553
string Array Data554
string Array Data555
string Array Data556
string Array Data557
string Array Data558
string Array Data559
string Array Data560
string Array Data561
string Array Data562
string Array Data563
string Array Data564
string Array Data565
string Array Data566
string Array Data567
string Array Data568
string Array Data569
string Array Data570
string Array Data571
string Array Data572
string Array Data573
string Array Data574
string Array Data575
string Array Data576
string Array Data577
string Array Data578
string Array Data579
string Array Data580
string Array Data581
string Array Data582
string Array Data583
string Array Data584
string Array Data585
string Array Data586
string Array Data587
string Array Data588
string Array Data589
string Array Data590
string Array Data591
string Array Data592
string Array Data593
string Array Data594
string Array Data595
string Array Data596
string Array Data597
string Array Data598
string Array Data599
string Array Data600
string Array Data601
string Array Data602
string Array Data603
string Array Data604
string Array Data605
string Array Data606
string Array Data607
string Array Data608
string Array Data609
string Array Data610
string Array Data611
string Array Data612
string Array Data613
string Array Data614
string Array Data615
string Array Data616
string Array Data617
string Array Data618
string Array Data619
string Array Data620
string Array Data621
string Array Data622
string Array Data623
string Array Data624
string Array Data625
string Array Data626
string Array Data627
string Array Data628
string Array Data629
string Array Data630
string Array Data631
string Array Data632
string Array Data633
string Array Data634
string Array Data635
string Array Data636
string Array Data637
string Array Data638
string Array Data639
string Array Data640
string Array Data641
string Array Data642
string Array Data643
string Array Data644
string Array Data645
string Array Data646
string Array Data647
string Array Data648
string Array Data649
string Array Data650
string Array Data651
string Array Data652
string Array Data653
string Array Data654
string Array Data655
string Array Data656
string Array Data657
string Array Data658
string Array Data659
string Array Data660
string Array Data661
string Array Data662
string Array Data663
string Array Data664
string Array Data665
string Array Data666
string Array Data667
string Array Data668
string Array Data669
string Array Data670
string Array Data671
string Array Data672
string Array Data673
string Array Data674
string Array Data675
string Array Data676
string Array Data677
string Array Data678
string Array Data679
string Array Data680
string Array Data681
string Array Data682
string Array Data683
string Array Data684
string Array Data685
string Array Data686
string Array Data687
string Array Data688
string Array Data689
string Array Data690
string Array Data691
string Array Data692
string Array Data693
string Array Data694
string Array Data695
string Array Data696
string Array Data697
string Array Data698
string Array Data699
string Array Data700
string Array Data701
string Array Data702
string Array Data703
string Array Data704
string Array Data705
string Array Data706
string Array Data707
string Array Data708
string Array Data709
string Array Data710
string Array Data711
string Array Data712
string Array Data713
string Array Data714
string Array Data715
string Array Data716
string Array Data717
string Array Data718
string Array Data719
string Array Data720
string Array Data721
string Array Data722
string Array Data723
string Array Data724
string Array Data725
string Array Data726
string Array Data727
string Array Data728
string Array Data729
string Array Data730
string Array Data731
string Array Data732
string Array Data733
string Array Data734
string Array Data735
string Array Data736
string Array Data737
string Array Data738
string Array Data739
string Array Data740
string Array Data741
string Array Data742
string Array Data743
string Array Data744
string Array Data745
string Array Data746
string Array Data747
string Array Data748
string Array Data749
string Array Data750
string Array Data751
string Array Data752
string Array Data753
string Array Data754
string Array Data755
string Array Data756
string Array Data757
string Array Data758
string Array Data759
string Array Data760
string Array Data761
string Array Data762
string Array Data763
string Array Data764
string Array Data765
string Array Data766
string Array Data767
string Array Data768
string Array Data769
string Array Data770
string Array Data771
string Array Data772
string Array Data773
string Array Data774
string Array Data775
string Array Data776
string Array Data777
string Array Data778
string Array Data779
string Array Data780
string Array Data781
string Array Data782
string Array Data783
string Array Data784
string Array Data785
string Array Data786
string Array Data787
string Array Data788
string Array Data789
string Array Data790
string Array Data791
string Array Data792
string Array Data793
string Array Data794
string Array Data795
string Array Data796
string Array Data797
string Array Data798
string Array Data799
string Array Data800
string Array Data801
string Array Data802
string Array Data803
string Array Data804
string Array Data805
string Array Data806
string Array Data807
string Array Data808
string Array Data809
string Array Data810
string Array Data811
string Array Data812
string Array Data813
string Array Data814
string Array Data815
string Array Data816
string Array Data817
string Array Data818
string Array Data819
string Array Data820
string Array Data821
string Array Data822
string Array Data823
string Array Data824
string Array Data825
string Array Data826
string Array Data827
string Array Data828
string Array Data829
string Array Data830
string Array Data831
string Array Data832
string Array Data833
string Array Data834
string Array Data835
string Array Data836
string Array Data837
string Array Data838
string Array Data839
string Array Data840
string Array Data841
string Array Data842
string Array Data843
string Array Data844
string Array Data845
string Array Data846
string Array Data847
string Array Data848
string Array Data849
string Array Data850
string Array Data851
string Array Data852
string Array Data853
string Array Data854
string Array Data855
string Array Data856
string Array Data857
string Array Data858
string Array Data859
string Array Data860
string Array Data861
string Array Data862
string Array Data863
string Array Data864
string Array Data865
string Array Data866
string Array Data867
string Array Data868
string Array Data869
string Array Data870
string Array Data871
string Array Data872
string Array Data873
string Array Data874
string Array Data875
string Array Data876
string Array Data877
string Array Data878
string Array Data879
string Array Data880
string Array Data881
string Array Data882
string Array Data883
string Array Data884
string Array Data885
string Array Data886
string Array Data887
string Array Data888
string Array Data889
string Array Data890
string Array Data891
string Array Data892
string Array Data893
string Array Data894
string Array Data895
string Array Data896
string Array Data897
string Array Data898
string Array Data899
string Array Data900
string Array Data901
string Array Data902
string Array Data903
string Array Data904
string Array Data905
string Array Data906
string Array Data907
string Array Data908
string Array Data909
string Array Data910
string Array Data911
string Array Data912
string Array Data913
string Array Data914
string Array Data915
string Array Data916
string Array Data917
string Array Data918
string Array Data919
string Array Data920
string Array Data921
string Array Data922
string Array Data923
string Array Data924
string Array Data925
string Array Data926
string Array Data927
string Array Data928
string Array Data929
string Array Data930
string Array Data931
string Array Data932
string Array Data933
string Array Data934
string Array Data935
string Array Data936
string Array Data937
string Array Data938
string Array Data939
string Array Data940
string Array Data941
string Array Data942
string Array Data943
string Array Data944
string Array Data945
string Array Data946
string Array Data947
string Array Data948
string Array Data949
string Array Data950
string Array Data951
string Array Data952
string Array Data953
string Array Data954
string Array Data955
string Array Data956
string Array Data957
string Array Data958
string Array Data959
string Array Data960
string Array Data961
string Array Data962
string Array Data963
string Array Data964
string Array Data965
string Array Data966
string Array Data967
string Array Data968
string Array Data969
string Array Data970
string Array Data971
string Array Data972
string Array Data973
string Array Data974
string Array Data975
string Array Data976
string Array Data977
string Array Data978
string Array Data979
string Array Data980
string Array Data981
string Array Data982
string Array Data983
string Array Data984
string Array Data985
string Array Data986
string Array Data987
string Array Data988
string Array Data989
string Array Data990
string Array Data991
string Array Data992
string Array Data993
string Array Data994
string Array Data995
string Array Data996
string Array Data997
string Array Data998
string Array Data999









