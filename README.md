# GIỚI THIỆU GAME: Chơi 1 trận bóng thú vị với những người bạn. Đây là game 2 người chơi và trận đấu sẽ kéo dài 1 phút 30 giây. Ghi bàn bằng cách sút bóng vào khung thành đối phương và giành chiến thắng.
## TABLE OF CONTENT
* [INTRODUCTION](#introduction)
* [Chơi game](#chơi-game)
* [Các thành phần trong game](#các-thành-phần-trong-game)
* [Cách chơi](#cách-chơi)
* [Các kỹ thuật sử dụng](#các-kỹ-thuật-sử-dụng)
* [Một số mã nguồn tham khảo](#một-số-mã-nguồn-tham-khảo)
* [Kết luận](#kết-luận)
* [Video giới thiệu về game](#video-giới-thiệu-về-game)
## INTRODUCTION
- Họ và tên: Phạm Tùng Lâm - K68J - UET
- Mã sinh viên: 23020678
- Bài tập lớn: Football-Stars (INT2215_52 - Lập trình nâng cao)
## Chơi game 
### 1. Khi bạn bắt đầu chạy chương trình, màn hình sẽ xuất hiện menu cho game với 2 options là Play Game và Exit:
![im](start_menu_game.png)
- Nhấn Play Game để bắt đầu trò chơi.
- Nhấn Exit để thoát khỏi chương trình.
### 2.  Khi bạn chọn Play Game thì trò chơi sẽ bắt đầu
![im](field02.png)

## Các thành phần trong game
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
## Các kỹ thuật sử dụng
- Thư viện SDL2.0, ngôn ngữ C++, IDE : CodeBlocks.
- Sử dụng kỹ thuật tách file cpp và file header để dễ quản lý chương trình.
- Tạo đối tượng: nhân vật di chuyển, quả bóng, khung thành, text.
- Dùng các kiến thức toán học để xử lý va chạm giữa các đối tượng : nhân vật với quả bóng, quả bóng với khung thành, nhân vật với khung thành.
- Xử lý thời gian, điểm số khi ghi bàn, âm thanh, hình ảnh, chữ.
- Tạo menu giúp game chân thực hơn: menu bắt đầu, menu thoát chương trình.
- Xử lý việc sút bóng, di chuyển cho nhân vật, khi ghi bàn sẽ reset lại vị trí cho nhân vật và quả bóng cũng như reset lại tốc độ của quả bóng bằng 0.
- Xây dựng 2 nhân vật MainObject và MainObject(02) được kế thừa từ đối tượng baseObject nhưng sẽ chỉ thay đổi cách thức di chuyển.

## Một số mã nguồn tham khảo
- Cách sử dụng thư viện SDL2.0, quản lý chương trình: tham khảo trên Lazy'Foo.
- Hình ảnh: lấy từ game trên mạng và cắt ra.
- Âm thanh: pixabay.com.
- Logic chính của game: tham khảo trên YouTube(Phát Triển Phần Mềm 123A-Z).
- Ngoài ra khi sửa 1 số bug như xử lý va chạm hay khởi tạo font thì tham khảo ở trên stackoverflow.
## Kết luận
- Em thấy mình đã trau dồi thêm 1 số kỹ năng trong việc tư duy trong viết code từ việc xử lý logic cũng như cách viết code hợp lý.
- Một số kỹ năng vè chỉnh sửa hình ảnh, âm thanh.
- Cách tối ưu code, sắp xếp chúng sao cho hợp lý để game có thể chạy mượt mà và hợp lý.
- Biết thêm về 1 số hàm trong SDL2.0 như các hàm để tải ảnh lên, tải âm thanh, tải text,....
## Video giới thiệu về game
https://youtu.be/DtAHysC-XRM
