![im](start_menu_game.png)
# GIỚI THIỆU GAME: Chơi 1 trận bóng thú vị với những người bạn. Đây là game 2 người chơi và trận đấu sẽ kéo dài 2 phút. Ghi bàn bằng cách sút bóng vào khung thành đối phương và giành chiến thắng.
## TABLE OF CONTENT
* [INTRODUCTION](#introduction)
* [Chơi game](#playgame)
* [Các thành phần trong game](#gamecomponents)
* [Cách chơi](#Guide)
* [Một số mã nguồn tham khảo](#Sourcecode)
* Video giới thiệu về game)(#Video)
## INTRODUCTION
- Họ và tên: 'Phạm Tùng Lâm - K68J - UET'
- Mã sinh viên: 23020678
- Bài tập lớn: Football-Stars (INT2215_52 - Lập trình nâng cao)
## Chơi game 
### 1. Khi bạn bắt đầu chạy chương trình, màn hình sẽ xuất hiện menu cho game với 2 options là Play Game và Exit:
- Nhấn Play Game để bắt đầu trò chơi.
- Nhấn Exit để thoát khỏi chương trình.
### 2.  Khi bạn chọn Play Game thì trò chơi sẽ bắt đầu
![im](field02.png)

## Các thành phần trong game:
- Nhân vật 1 đại diện cho người chơi 1.
 
![im](nv1.png)
- Nhân vật 2 đại diện cho người chơi 2.
  
![im](nv2.png)
- Qủa bóng ở giữa sân để khi xảy ra va chạm giữa 1 trong 2 nhân vật với quả bóng thì nó sẽ được sút.
  
![im](ball.png)  
- 2 khung thành ở 2 bên để khi quả bóng được sút vào trong khung thành thì tỷ số sẽ được cập nhât.

![im](khungthanh.png)

![im](khungthanh(02).png)
- Text thời gian để hiển thị thời gian còn lại của game.
- Text tỷ số để hiển thị tỷ số của game.
## Cách chơi
- Nhân vật 1 ở bên trái của sân sẽ điều khiển bằng cách di chuyển các nút W(đi lên), S(xuống dưới), D(sang phải), A(sang trái).
- Nhân vật 2 ở bên phải của sân sẽ điều khiển bằng cách di chuyển các nút trỏ lên(đi lên), trỏ phải(sang phải), trỏ dưới(xuống dưới), trỏ trái(sang trái).
- Người điều khiển sẽ điều khiển nhân vật của mình va chạm với quả bóng, khi xảy ra va chạm thì quả bóng sẽ di chuyển theo 1 hướng và tốc độ xác định và di chuyển vô thời hạn(tốc độ di chuyển của bóng sẽ không thay đổi, nhưng hướng của quả bóng sẽ thay đổi khi tiếp tục xảy ra va chạm giữa nhân vật và quả bóng).
- Khi quả bóng vào trong khung thành của nhân vật này thì sẽ tính điểm cho nhân vật kia trên text tỷ số giống như tỷ số của 1 trận bóng đá thật.
- Thời gian của game mặc định là 2 phút và thời text thời gian sẽ giảm dần. Khi hết 2 phút thì sẽ tự động thoát khỏi game và thoát khỏi chương trình.
  ## Một số mã nguồn tham khảo
  [lazyfoo,](https://lazyfoo.net/), https://phattrienphanmem123az.com/.
  ## Video giới thiệu về game
  https://youtu.be/DtAHysC-XRM
