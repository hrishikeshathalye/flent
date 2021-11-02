## -*- mode: python; coding: utf-8 -*-

DATA_SETS['VoIP']                 = {'length': VOIP_LENGTH,
                                     'host': VOIP_HOST,
                                     'local_bind': VOIP_LOCAL_BIND,
                                     'interval': STEP_SIZE,
                                     'units': 'Kbps',
                                     'control_host': VOIP_CONTROL_HOST,
                                     'marking': VOIP_MARKING,
                                     'runner': 'voip'}
DATA_SETS['VoIP::bitrate']        = {'units': 'Kbits/s', 'runner': 'null'}
DATA_SETS['VoIP::delay']          = {'units': 'ms', 'runner': 'null'}
DATA_SETS['VoIP::jitter']         = {'units': 'ms', 'runner': 'null'}
DATA_SETS['VoIP::loss']           = {'units': 'count', 'runner': 'null'}
DATA_SETS['VoIP::induced_delay']  = {'units': 'ms', 'runner': 'diff_min', 'apply_to': ['VoIP::delay']}


PLOTS['delay']              = {'description': 'Delay and Jitter',
                                    'type': 'timeseries',
                                    'axis_labels': ['One-way delay (ms)'],
                                    'series': [{'data': 'VoIP::delay',
                                                'label': 'VoIP delay'},
                                               {'data': 'VoIP::jitter',
                                                'label': 'VoIP jitter',
                                                'color': 'green'}
                                    ]}
PLOTS['delay_cdf']          = {'description': 'Delay and Jitter CDF',
                                    'type': 'cdf',
                                    'cutoff': VOIP_CUTOFF,
                                    'parent': 'delay'}
PLOTS['delay_box']          = {'description': 'Delay and Jitter box plot',
                                    'type': 'box',
                                    'cutoff': VOIP_CUTOFF,
                                    'parent': 'delay'}
PLOTS['induced_delay']      = {'description': 'Induced delay CDF',
                                    'type': 'timeseries',
                                    'axis_labels': ['Induced one-way delay (ms)'],
                                    'series': [{'data': 'VoIP::induced_delay',
                                                'label': 'Induced delay'}]}
PLOTS['induced_delay_cdf']  = {'description': 'Induced delay box plot',
                                    'type': 'cdf',
                                    'cutoff': VOIP_CUTOFF,
                                    'parent': 'induced_delay'}
PLOTS['induced_delay_box']  = {'description': 'Induced delay box plot',
                                    'type': 'box',
                                    'cutoff': VOIP_CUTOFF,
                                    'parent': 'induced_delay'}
PLOTS['box_delay_loss']     = {'description': "Box delay/loss combination plot",
                                    'type': 'box_combine',
                                    'cutoff': VOIP_CUTOFF,
                                    'dual_axes': True,
                                    'axis_labels': ['Mean induced delay (ms)', 'Mean loss rate'],
                                    'series': [{'data': 'VoIP::delay',
                                                'label': 'Induced delay',
                                                'combine_mode': 'mean_span',
                                                'axis': 1},
                                               {'data': 'VoIP::loss',
                                                'label': 'Loss rate',
                                                'combine_mode': 'raw_seq_loss',
                                                'axis': 2}]}
PLOTS['mos_combine']         = {'description': "MOS combination plot",
                                    'type': 'box_combine',
                                    'cutoff': VOIP_CUTOFF,
                                    'axis_labels': ['MOS value'],
                                    'series': [{'data': 'VoIP',
                                                'label': 'MOS',
                                                'combine_mode': 'mos'},
                                               ]}
PLOTS['bitrate']            = {'description': 'Bitrate',
                                    'type': 'timeseries',
                                    'series': [{'data': 'VoIP::bitrate',
                                                'label': 'Bitrate'}
                                    ]}
PLOTS['mos_upload']          = {'description': "MOS and upload throughput plot",
                                     'type': 'box_combine',
                                     'cutoff': VOIP_CUTOFF,
                                     'axis_labels': ['MOS value', 'Mbit/s'],
                                     'dual_axes': True,
                                     'series': [{'data': 'VoIP',
                                                 'label': 'MOS',
                                                 'combine_mode': 'mos'},
                                                # upload sum doesn't exist for
                                                # single-flow tests, so use two
                                                # globbing expressions to
                                                # support both types of tests
                                                {'data': glob('TCP upload sum'),
                                                 'label': 'Upload',
                                                 'combine_mode': 'mean',
                                                 'axis': 2},
                                                {'data': glob('TCP upload'),
                                                 'label': 'Upload',
                                                 'combine_mode': 'mean',
                                                 'axis': 2},
                                     ]}
PLOTS['loss']               = {'description': 'Loss',
                                    'type': 'timeseries',
                                    'axis_labels': ['Loss count'],
                                    'series': [{'data': 'VoIP::loss',
                                                'label': 'Loss',
                                                'linestyle': '',
                                                'marker': '.',}
                                    ]}
PLOTS['delay_loss']         = {'description': 'Delay and loss plots',
                                    'type': 'meta',
                                    'subplots': ('delay', 'loss')}
