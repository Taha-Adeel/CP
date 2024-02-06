#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

vector<int> prefix_sums;
string prefix_sums_brute = "#######$###&###)###-###2###8###@###H###Q###[###g###s###þ###ð###á###Ñ###À###®##$.##$D##$Z##$s##$ñ##$Ö##$º##%,##%L##%m##%ð##%Î##%«##&B##&j##&ì##&Â##'1##'_##'ò##'Â##(8##(m##(Ý##(§##)Y##)ì##)³##*R##*í##*®##+[##+á##,)##,o##,É##-H##-ì##.'##.v##.º##/`##/Ê##0T##0Ó##1N##1Õ##2O##2Ñ##3X##3Ã##4j##4®##5ú##67##6Ù##7`##7®##8ð##9N##9¸##:ô##;N##;³##<é##=`##>*##>Ñ##@{##AK##A«##B×##Cÿ##DY##E4##E¶##FÔ##Gï##Hu##I]##JE##K0##K§##L³##M½##NÆ##OÎ##PÒ##QÒ##RÐ##SÍ##TÆ##Uº##V«##X5##YR##Zr##[é##]Â##_/##`Z##a÷##bÇ##d;##ez##fÆ##hN##ià##k>##lá##nQ##o¼##qì##sd##uH##w4##x¦##{&##}+##ÿ1##ýY##ûü##ù¾##öY##ôÐ##ñX##ï¹##ìþ##éE##æ'##ä·##á¿##Þ¹##Û°##×'##ÔU##ÑÔ##ÍM##ÊÓ##ÆW##Ã©##¿ß##»y##·|##³ú##¯î##«µ##¦Q#$&ë#$++#$/}#$4*#$8î#$=W#$CK#$HZ#$Mz#$RÚ#$X.#$^ë#$dY#$j,#$oµ#$uÅ#${¹#$ý¬#$ö.#$ðB#$êb#$äÂ#$Ý}#$Ö@#$ÐÀ#$ÉÄ#$Â¾#$»©#$³C#$¬ô#%$=#%+¦#%4(#%<A#%Eg#%N$#%VÞ#%`n#%iY#%rl#%{þ#%úã#%ð(#%çn#%Ý##%ÔÒ#%Ê´#%¿k#%µ°#%ªõ#&)T#&4i#&@ô#&K±#&Wã#&dÚ#&pÂ#&|¨#&õE#&éú#&Üq#&Ïq#&Ât#&µâ#&¨¦#'.j#'<)#'JÛ#'XÏ#'h~#'wâ#'ø·#'èx#'Øú#'ÈÍ#'·+#'§x#(2=#(Dq#(UÍ#(hE#(zj#(òì#(ß9#(Í½#(¹g#)#2#)7C#)M8#)cd#)y,#)ïÉ#)Øñ#)ÀÀ#)§Q#*9°#*T¿#*o¾#*ô[#*Ùæ#*»©#+,Â#+L¬#+mi#+ñT#+ÑÉ#+°ç#,;F#,aç#,øá#,Ða#,¨ý#-JD#-tE#-à0#-µT#.>z#.k¼#.åi#.¶.#/Cì#/un#/Øã#/¦)#0V¼#0óº#0¾P#1@;#1wÈ#1Ïe#22X#2põ#2ÑN#34¬#3uI#3Ê*#4@6#4üI#4»¼#5P¨#5äÉ#6.##6y[#6·7#7a:#7Îx#8KÆ#8à>#9:A#9ðP#:,'#:úÅ#;(Y#;ù]#<+½#<óN#=3|#=èò#>D0#>Õü#@]G#@¹K#Ay°#B-Ø#BâL#CT@#C¼ÿ#Dýp#E>ë#EÇë#F|=#G@þ#GÂû#Hû©#ILä#I¯ß#Jß%#KoN#LF¿#M#Z#MÈ±#NèÞ#O~H#PfN#QO·#R;ë#S+ç#S­É#T·Ú#U¿í#VÀ÷#W¿:#X¿²#Y½«#Z·>#[©`#^0`#_FK#``P#a{í#bçä#cÅ/#e(1#fN¯#gvl#hßh#i­J#kYV#lå##n%)#oi¯#pÍX#rK|#sáæ#u>ç#vå,#xIY#yÉa#{pí#}3°#~Èñ#þùê#üX@#ú4à#ùµz#÷Õü#õé`#óù8#ñû$#ï÷3#íî=#ëäý#éÓú#ç·¹#äJ§#âê2#ß(6#ÝuÂ#Û±H#Ø|»#ÕE`#Ó´m#ÐâL#Ívµ#Ê^î#ÇZr#Ä]¬#Ábè#¾rD#»Î¿#·I<#´âK#°:g#­ìà#©5)#¦Öç$&öJ$*iÖ$.eþ$2mß$6ÿË$:ÝÅ$>²f$DP2$HØa$Mbù$R8$$W#Ù$[ªs$a¦v$g5È$lW³$qßÅ$w=«$|êB$üH÷$÷²µ$ñÙA$ëÔM$å¹l$ÞCu$Øõæ$Ñ(×$ËÙ¨$Äob$½T¶$¶E.$¯8f$¨52%'ÔO%/mU%71á%@C&%HhO%PÔ±%Y9$%bî2%kF;%sÆñ%|wÎ%ùlå%ðtP%çÞä%ÝNî%ÓVè%É~b%¿Óê%´)y%ªmÚ&(¶÷&3Üd&>èÒ&K3|&Vð)&cZn&oeø&{ã¼&ö0þ&êÌ9&Ýöý&Ð~ß&Ã¹k&µìû&§äÒ'0$<'@0F'O<¾'_Pk'nów'~ÒA'ï>ì'ßõI'Î@7'¾¸ÿ'­äå(,îÉ(=ÓK(P$6(b»¿(uYð(÷Ò3(äO·(Ñâ>(½ÒK(¨_´)5.l)KP3)aÆÛ)wð6)ñv¶)Ú¹ä)Âéé)ªèì*7NV*Q.÷*kCç*ú[À*áÖ2*Çêp*¬­p+8kÞ+U:·+rDî+ïÃh+ÑªØ+²DÎ,5+_,U>*,výw,ç^ã,ÆÄ¯-%9Ì-Håó-mm/-ì[1-ÇXÛ.&ùí.MÇ#.xV­.ÜC^.±_÷/D/=/rVA/ÞýF/­Øù0M²a0þð½0ÌÇ+1/1{1d´à1ä÷³1­L³2Sðt2ò.¼2¸Ùi3M&±3ôB<3¸uÄ4Oü¦4ðÖs4¯wU5^{À5Û/ú62746{ê46¹r87Zmg7Ù¹B8;Ls8öòÉ8«©v9sÐC9´.è:l«.:¹²l;k]=;·y°<oÕy<«,ù=û~¹>2)Ð>ä´V@M{è@ÅÔ:AtwAB.E¾BØÉªCk4jD1OØDÏãîExËÁFAdXF»üÄGîªýHeù{I8ÚÃIºË«JßÉ«Kÿr%L_hýM=åmMªé#NÇXùOå¦TPøº&QtURRfcÇS]Æ$TUp³UQH÷VO:JWM¹ÙXN``YT®åZfï¸[{|ì]îôd^Ô_j_¹v2a+(ùbN÷ùcx©ìdÜ·ee®¶@gI¬Rhÿe$iÃn»kB§ÛlýæEm¸y°oWÔupß¿ar8ÐÚså7puDVÞvÙþâxemâz(:Ý{ÛyÑ}h»Lÿ,}ÂþÏ;kü}ÅtúK¾çø%å7÷Ä4TõàPióñDÎñ~kìïu®ÀívÄ2ëþÜaéñ°ªçàê]åÏi>ã»6Ïà7SRÞoýãÜØàõÙ-Ý¦×üô<Õ¨mæÒ{CÅÏ>byÍÃçsÊûÈ>ÇY(ÆÄ0óÄÂ½SF¿Ó0°¼ÒjË¹Æ×`µ6ýa²u«k¯ÉGé&3²%)ß|«-e3N1+kw4¿SP8Ýß´<ív'AÓ¯ZE´ÒÆJ65~NXéCRÑ²>WO»c[¿H=ayò³f~pÎk¼ÐIqoJøvªXô|õàWüU{yö(6ªñÊ%Lë²ÞZä0í¸ÞYcÇØò1|ÒÀ5ÿË:j&Åð¶¶¾A|´¸¾¯k±Ìr3'óÐã.Ôºó6435=zÝ÷F4s9MÏUyUÃÌê^¶ÁÎgHÂ`oþüawÀ;gþKÄ×öï¼1íõÎyäÐÌ2ÚXx-Ð'cîÇºæL½Ò$O²8Ps)oìB3»ng>æ3NJâ¸)UÕÊÚa¿®ÒmXó8xÊÄ;úv·PîÖPmáBÕOÕÞ@ËÈOHÅ»keÁ#õ¸å0¬Çï>½þåNüM&^Kç2mx8O|Ñ1Éò4Ð~âOºÈÒßÄÃÁXEÁ±ªpµ1÷ÉâCÜLJUÏ×Ìi=Õ8{õÒdðkÆmÝuCdÊ¶¯s¶çßy/ñ*³EÿÌ]ZsjÙpµÔ|ø«d2á7@rÊ9ßy³=4G5XMwNþo³h-6Nþ°1µåÀ7²Ì¬H¦²Ýo¾9ÅÙ®Uç÷ÂqÂ]Pñwb4ÔÒÎÂ¶@ðª9à°mZ/,}zxw3äÒÛÙÃÃ87/»ÆCRl6ùu=Èxæ8'ÊÂ¼*x4ú.«ZÀú|ý­OjÖºÌö#ë=îLÅ¸rvFIIàêÅ=¶<JCEÃn%qÊ7õßÅ@æ°uv2QGårüç&fËÖl§8`bjl>npÞ{oq'´'ô_ùÝbæ+9s$)D_`@³fätW´'áîIe§ØwÛfuO4m¼zuE4äÇëüÜNz3wénú91«õe~ê|lµdðvjk¦XÆR2éZ¦$ÇÒqþ|Q8ÖmÛÙODSí^kÍÁ·VdÀLðº7#azTÀË/Yì2ê°Ô@QrÔIÃalIyhèu=L|àÍùêhz²aûCö¬.ÁÁÈ»ñqQ|_ÇÞ»2¾{<Æh)kìóý1oã¶ÛOfÎ06|·¦±ÌÐ0Æ2®LÚuºÙíÜØdüQ¹-t)søeÀtîW~Y±MFW^CÓÔ7B6(sBnK'Fr@ÇSh`Heø¨Îx¸ú^îjPFÕíÑÔ¹Ö%³7ö0Ü_Ü2Ñø°óHÍ¸-@5WÇ¿l/ï%Ý5»K*ÉïàkKÀÙÍcaÏLí%{çµ¶ã:ÜÍuðñÇó;ºÆßÛNé¹gnìÏ)ëÑ^ãy-²kÙ_Î=©&$¿ÓnTæyVP|(hJgpb©SùQóPPÃJQï{ÞTøÞÔk3JTú©ö,Û¸B_»Måß8m®¾a7)®ëö/,¶Î1ÊXqøUçmßÔ+«5%|x-·0oïSé¯¦§PFÓtÄÑXÑyã¾I<Ôáà¿Q_3ÞaVOõÉ-çësÖ<áJÒ_ÇÎµc*<ÿÁ]ä­áçÙðZ6I7§òòºö<&èþËÐ/Âùc¨@[9³ÝO.ÌdQÒ1Yy­üÿÑÔG0Jø¼üæ­*ÜQ*/§È´:GvG=×Aá0æ·÷|]Ågl:)5ÈÑKÑ]êtØlXáÝ÷@%¿A3}Úv¬1[>×Þæ0§sóçÌ÷9Þ>ÞG0o½ºçÊTÍÄÑµ·2'Àm8Y²vêBaízµ¯èøeÓ±_IöÄòüoFF÷V.¶½O[µ*I×cmu´VÖ0]ê´ºR#ÖËµ`9%apëP-yèÏäV%üÌðdfrm§itT²ÒÓVäPÿs)ÛuÖÏb°ªîc{öiyÂ­½ìêôÿ¼8m0g©üâ¿#Ú¯rÍÐÓMîbÖ²ØÒò³TþÓ,qG|ÏyqÞ÷ÏòipÏæ³Õ0À&,Ê®¨ëÑyó`zÛè.M<U±º>ñ>°Lµç`4óö§ÁuÒ®ùËXéajyÅîpÇ#É^µ'n9Hð¶UÆuJøÿÖÀÆJ±Q¼%iSe&vo³TDM·øÖtC8ô5e,]TÏ#Hüµ&1¹üi±ão²ÖÅbÛ=êfÞP:ÚJÇ=aÜÕïÎRa¹Atÿzë*ÂÕoü°IXÏIYEeÆü1Ôp¦AH³½v_nL+ãÀkçáx8¨3ja}»»ÁI`çJ°ÄùÎÄL©þÌ®4¹ößXXk»²òÕpLð¦Õ¬»ýNxXò|S­RÎaoZ^é)Y½×uÂ'jÎI¼aWw¶4'á,P×ÀGà+ÒÛbZç¾×oËhJ¬_;JI­HñÇÜÅl¿<Oô&1ln÷æµF{;´Kn²îZ-µêÊ=8rÃ3_áËÊýkü9ÖEúôÛ.&CõÝÁE)øý±yï@+WaIû@ÔÑ`ÉG½¹ú8PÕ§îB²KW|ÿYÆ=ÉlÚ4J¶Qùù]$×_à,xñéHÿlÒ#.ma.ñ»ÑRL[,ö/¯ÀìOuãÎc74gØÏÂxi§èÒÀ.ôMU1#vââ6Ðe×Mq7óZÿýp`YÑmp¾DtÖë>ât³æásê¨C[ØSk°IgcÞ8máì±ÿW¸ôçÞ¿r(ÆUvõPRÌdmhÄm,=bÎè½D}`ú{ô¬Ì0Þ«®w«Æøú$N[ï¹2ËKc´eJ~´½þdN_Ýàà·%§1µî³LÍ~±Sê¯ØrÄë°÷7æ,U[ÇëüpliÝ®°)à3Ií+CãÙ~õaû~ðßhüY[:ÍKNþÜá-ñbýÀ)¨aéùç(elÁÞôÃãóëºýø*YpFÛºÖq(ÚiÃ8Éßi+)ºKdà¹×0Þç1K4ãiö¦êìhlZÅþy;e¾h&áÀà'Ý}Iææ¿¿ûÉwäcÌàdéõþ³Ãmw`@¾bát~dÚö$l²$l/¹$±I(­QJhð»î_G»·7I¸çåOfFåñ6l`6´ó9&|ÏMSÌuÇúþ¾Û«Í`oñð]¾ï8PQüúcdMz=b+ÕûdâP:@©(#sJ¨É/çéyDæà¾g;cG'B¨}¬EýùªIOÈ7½[¯,c´ëxoÔdáS'aTU09m(sU>ÞfÛõN¶hÛãîûÀLýÛo­j[ön¦Fck>ûûx§YM1þ[µbÐôfCh)rN]4î´Ïÿ­¨kjòÀ©TA2ö9±¯h`;gS»V%ÓÞ<MÈÂ´¼adæÿ½´Wí0-<èó[j¶rV°wôó²íB-ú¸6&Ö´IÝ-gðc²­-åkÈlsõîèÕÀÖx;ÆEP^Ü%Æ2Vª:Òæ9ÈßNi71od­È8Õ]Ûp½@ÅÐO/½a¿ÒÖ¹©)~9ØJvû³æl_­Ë7»ßsüUûJákÈKV8Obîßûl4­JEBF¾VÝ¹-¸bT¦gkæJ³óÐlhKÚ+r×Gí>àZÛpâ*Ò,W¿'ZJR/ÿlÏ9½áÞ[ÍU-ÚýîÔ×lOïaAÎ2³ïqýDYËSÂt^tÑ/Û§,xõDõ0Éó¶6þ+%Ìo+0)½²ï¼évõúp,ÅLâÕó+FH+m6#xRÅ×Ã~Ù_·Ê>sc2_,LY¿rÙ°K8;RùÍý´m©îTåµ{CqÛN3Í¯ï¦1Ä¸6»Ê¦yZã5OÁ}y.0ÐÜðÖ:Öd%Å¯ºÊl.Y¶LNFµÓ0nê:1è5>½¿<gªA·ø4é/ÀEÓµa&2»°+Éj©©7³düyy÷¦>S>8ÛA=1ÃAO,þäüË'Vÿ+ö,ÛE@ëNeR#Z5ØÆ,ävÂ±Ý<×åúmÁOÿÖýÍd`,{6DõKéª^÷aÅµä²LCKÅF[×ø¼Ô.]ª<xeðêEÆòÒsü¿.6ìÝó­P_²Yò·a.ïcò&ËýUÄPûÞQ>8x»Ì¼F¬Ág@KÙ®sÓ§âõ_.pe[¨Þe~²)j¸k6î&´9<qFaüíÎûP·Vn²Of´(ÂraAôIãÄþ,¿8û§önÏÜÙsaKh}äQ#&ZáÚÏqþ'GÚð_4ê«p1ùQeÛåØwB¯üd»1é~Û|,Ãmx°NàNf%ÔÐé^µÒlÄ+N~±n&p´fÊªß»MS@ali=R¶8]ÿ,RÄ5(6f5m§.Ãq:·ÍpùòÅk3­ÿpÊÍµDÆýgû«ëÒPä,ió,oÄÛ¼*ÃC×os2h9ó`&Kj~ÙId_V2åjH_ù=Ç0ÌC/¦E;ÂÊEÛâÁÍ@QJgú1ÈþJ^pÀE½u>=íi/ÚÚ·juÝ.x<Q-°rù4bY$A}oÙF~Bzït¶_n$ìïA³Í©ÿÇÎÌÁm¼Ô«}Ç¿ÕfB¹OM(HmV<½ô<W8±d2±êZGôµ[<Tâw9ñ+3x«'´ªæTÀéÎ'uã@ÕYÑÒAº»îæYq9LÊyå0÷óGçöÜÂÕÀpQ`ÞnxcÆ^;ÿÏRTPpcÍ°ÜxÃD&áYuÚêlÿéDÇGºQ7ÇsaïætãD3Â·è&À^E<¿ÅÚ°ÑZnòÃ½®+ÏºÚÉ÷¼_}WðjÿYVÀäCáÃLÖÉ.1ÇõÛHÅu6ÛÞ¾Ì,nÁÉoõ^º@pé=áåÜÄâãÎDýÚÛJQØ¬ÿvóD+·Ju¿:7y¦TÖêrS+TÐë¸^*.ÿj:ñ4­/07nYéø<|ÎgT^Ai¶}.ÐGt:hCSÂEJiB)øT.,gi]/jr´ÇÿÂ='zµ:ÊEä[âKBÅ;æXÀ¾á¨'x{ûänyÔzÈGÑ°ã&@Cû­ô¸ÝzÁ<ÙPâ=t3$ÁÝâcáHdÄQÚÁãûÈÛ×#ìÒ#VFKß°°=K»;X3½)ïxIIÙ9ïv§*­5×ê_Ñ÷n0ËHèñÿñ¨lQVå9W]ÒaÛ¦6ýc1ô¯1<í©²^½­|,MièÃ_îë¸a-]¬Òzp¾©FT@$A%)Åëb0j5iê&71VéKÒXÖÕùkKÄýð´­/óðæ*8õÏ5°IeZäa]dÛ~:·¬.å.·q«kÿÇªcÖ²ðè}©Di2ê'é5âx&C©TSÆ;«éXÛþÞì>ûEØÀKôåóÇ.*¹T:75ÝºÃ8@g0ó½¼¶¬êà±zäÕôHwÝÍd±3´FÏZØåH¯xÙ7sMd%ü]ê*DGþtmÇ>xã<<lLa8ð-Åûí8®¾².,ÇEFÜ6fj­4þ}-p<#TGs>ê_þV­<h±@´jÁê=ìwªMÃýcÿ,Ä,DIUÂì+k­©WòÎuî8ºÑ)Pýã0ð·rzú¾1câ¦þFòåqòÎ6gbh@ko}nÁ'æô_zl$%6Ö`:«=áú±0fÆÜ´å¬{ë[U2ÍzÈ<vwêCçåHÃrláª[îô|ó»>ÂÎ1Ê6K²WdÂàmûMôÎê}OndÚx5LºbVæ)´È7á`Aqü1(.ø©H¼ÍJ®dÖ­È¨6¸)«züªîýµísÏBmü9ìÓÓk»ítÌÉ|ª°/÷1U±^ãÖ¨Ûºvx±åÂ{jPLÊ#wÞùùñ/ÚïÕLÄljKÎp¹Ñug:`Âù»Ü.ÃöSQ3-Àè´eí¯¦ùt43ýåïAi$/¿1-¼IÛ´û±²éôm¿mäT>|süÄýòwì.´+ÆÞ:ÐGv¨¼Ù>þ¯2Ý,äzss.+Ð¿zqíùNú¶/cÔJÏà¾Â9-ßy&êÉgü(~Ñæÿ©ðÿkK[YçíUëÝ¹¯XÄ9[gqxYRzzh¬#¶OFñÈ<ÎØ3W}ü%OÝK9KcUÖ°Ë¼0ÊtqGI¹WÒý|%´»5ñ¼b¬LIÊÐkûSðûY»»²ê*^é¶Èx0mfçÊ§p|§iÛÒnCK¯ÈBHÍ»Þ_ÛWÿ²Ïþ²V<Qæ+¿÷È´ÄK¨CécMÌ¾Í-róø1gHäãÑkµBrÙ7Çn}JÃ:®gçpi«|`ÍgÚéS=ºòòT4V½gb¹,Åàá9¯éc`¬-^-2ïòªõ§nÃR^è*áÆíìéÑNõ~Å<þáÝQJ,zÆÕº.ÈYÜ%k§qÙçÄNcþqaßÏkÎòÜe®kNÊø×Ó¶I,Iâxÿde>nð²Þo27;i¶÷h~ÕÑ»õ2lWÁoInî$LWÃn]ìl($Ê;9~>¹·v«Y[9;ùb°«/Ê½EªJwkxØÏå_ôd²Ï{Lð:A2æ]5ú¹iÃÝm¸ÿnÊö±Åéöº­ùrÜ¿»A´SæÕÂ(vîÇ>0~cãßÈïtå÷~ós;NÑçÉÑÜýïùµµë:Ïs·#u¬Ðä#»þ<^·m,}V#ÒFÓUnêÑm¿f¿cõÅ2ºÛ&¿_¼¿¯ñ8Q_-ÌTÁêøÎG-êo¿:ñ4W©k@LÏ0_Êã¿N7bÔ9ëzK#u^Ý§rìc{-ÌT<ÛÅÂ7mQ_Ò´tBWøA7ûÍ¬<Ê;QÄCË¹Àf&zt{ÐMY4j¸6c¬1H-ÛÛ]lMbÅ#*d$Ú2²q[ÔÝáÌþ{.ô^+Â/1I>³5xý#òþËm7jðw§85xß¦QÒ$<&+s×ºò]kuT=WJ,=ö2xôá¶yuÚ¯ÉC&Þ[YÆìÑcAXÆðìÙo¹³ÑÌc3y%îq3üÔËU°M)ÿëV]ÖøSúÊñ¼ïàéC>dòö&gEÕò5¶fáã·q°[ò²bÂê¦Íy¬KYM­>qËÒMDo=¿7#Tìñ±ë&RX%äð9Õi¦V÷a§d5%ÔÕhõñYKsðÞ=B4%6j#d7­´³Ði§àïKL&/@ðòYvì]ªGÐÜEþ9*(Kí8ÝáL´ÑÏ»2áB3ED3uUµ§Í{4YzR=åºé¨êh:AÚ«ð&ßmØ5·ûzE~å5s$X¶ëX,8TkàNFüïÐÝ>4Í9'ªZ6¸MÐãìbwDèýé¾»lVYëéºs¶H0iPÔ=N%Ù³2zÔúC´ýHË»_ºòÄª;ùãG%í¦~î¹·<ÐE{Lóu1§IYü¶³7ÜÐêµº@i{ükrI.Ãâd»DÁÄßÀm±jàGu]ÜxëÑ°³°¬=õæì9GÛ»ö¿¸s7Mhä^,©¸ë²µÒðJï¦xIÕÔ±<î¶XzÈ¬îÄ)E7ØÞ*yå@^®Ì¾À¸tNÑ(×õÅLCå{è»®CF>F­ôálÍ³è3QbÔ[m¨dÅëüñÜÿ]²xº/uî>ø>=ô}êuFE*MÌó5ìICçÊ0DIþàvq/ªgÀYaúUcpÖ9»6Òïóêrr¦kuImógñckèu/ØbàZ2ZVô|e:ý+_o²7JáÃ³tÄóªïv,5&ÎÓ¸+SmzÒ6âpåF¶-nh6|sÅÀS'ì=Ê-#ßT·ÛK)pÞæð_3ÓnLCbáü@Ï¶¯·ß9çÛSëÛ";

int from_base_x(string num) {
    int base = 180;
    int res = 0;
    for (int i = 0; i < num.size(); ++i) {
        res *= base;
        int digit = num[i];
        if(digit < 0) digit = -digit + 126;
        if(digit >= '?') digit--;
        if(digit >= '\\') digit--;
        res += digit - 35;
    }
    return res;
}

int main() {
    for (int i = 0; i < prefix_sums_brute.size(); i += 4) {
        prefix_sums.push_back(from_base_x(prefix_sums_brute.substr(i, 4)));
    }
    int t;
    cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << (prefix_sums[r] - prefix_sums[l - 1] + MOD) % MOD << '\n';
    }
    return 0;
}