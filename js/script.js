// function triggerEmergency(color) {
//     let title = '';
//     let message1 = '';
//     let alertClass = '';

//     switch(color) {
//         case 'merah':
//             title = 'Status: Bahaya Tinggi';
//             message1 = 'Tombol Merah ditekan. Segera ambil tindakan darurat.';
//             alertClass = 'alert-danger';
//             break;
//         case 'kuning':
//             title = 'Status: Bahaya Sedang';
//             message1 = 'Tombol Kuning ditekan. Waspada dan persiapkan evakuasi.';
//             alertClass = 'alert-warning';
//             break;
//         case 'hijau':
//             title = 'Status: Bahaya Rendah';
//             message1 = 'Tombol Hijau ditekan. Tetap waspada dan siaga.';
//             alertClass = 'alert-success';
//             break;
//         case 'biru':
//             title = 'Status: Informasi';
//             message1 = 'Tombol Biru ditekan. Periksa area sekitar untuk memastikan keamanan.';
//             alertClass = 'alert-primary';
//             break;
//         case 'putih':
//             title = 'Status: Aman';
//             message1 = 'Tombol Putih ditekan. Tidak ada bahaya terdeteksi.';
//             alertClass = 'alert-secondary';
//             break;
//         default:
//             title = 'Status: Aman';
//             message1 = 'Tidak ada bahaya terdeteksi.';
//             alertClass = 'alert-secondary';
//     }

//     const alertDiv = document.querySelector('.alert');
//     alertDiv.className = `alert d-flex align-items-center ${alertClass}`;
//     document.getElementById('emergencyTitle').innerText = title;
//     document.getElementById('emergencyMessage').innerText = message1;
// }